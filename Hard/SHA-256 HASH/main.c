#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROTRIGHT_32(a, b) (((a) >> (b)) | ((a) << (32 - (b))))

#define SHA256_EP0(x) (ROTRIGHT_32(x, 2) ^ ROTRIGHT_32(x, 13) ^ ROTRIGHT_32(x, 22))
#define SHA256_EP1(x) (ROTRIGHT_32(x, 6) ^ ROTRIGHT_32(x, 11) ^ ROTRIGHT_32(x, 25))
#define SHA256_SIG0(x) (ROTRIGHT_32(x, 7) ^ ROTRIGHT_32(x, 18) ^ ((x) >> 3))
#define SHA256_SIG1(x) (ROTRIGHT_32(x, 17) ^ ROTRIGHT_32(x, 19) ^ ((x) >> 10))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

unsigned int k[] =
    {
        0x428a2f98,
        0x71374491,
        0xb5c0fbcf,
        0xe9b5dba5,
        0x3956c25b,
        0x59f111f1,
        0x923f82a4,
        0xab1c5ed5,
        0xd807aa98,
        0x12835b01,
        0x243185be,
        0x550c7dc3,
        0x72be5d74,
        0x80deb1fe,
        0x9bdc06a7,
        0xc19bf174,
        0xe49b69c1,
        0xefbe4786,
        0x0fc19dc6,
        0x240ca1cc,
        0x2de92c6f,
        0x4a7484aa,
        0x5cb0a9dc,
        0x76f988da,
        0x983e5152,
        0xa831c66d,
        0xb00327c8,
        0xbf597fc7,
        0xc6e00bf3,
        0xd5a79147,
        0x06ca6351,
        0x14292967,
        0x27b70a85,
        0x2e1b2138,
        0x4d2c6dfc,
        0x53380d13,
        0x650a7354,
        0x766a0abb,
        0x81c2c92e,
        0x92722c85,
        0xa2bfe8a1,
        0xa81a664b,
        0xc24b8b70,
        0xc76c51a3,
        0xd192e819,
        0xd6990624,
        0xf40e3585,
        0x106aa070,
        0x19a4c116,
        0x1e376c08,
        0x2748774c,
        0x34b0bcb5,
        0x391c0cb3,
        0x4ed8aa4a,
        0x5b9cca4f,
        0x682e6ff3,
        0x748f82ee,
        0x78a5636f,
        0x84c87814,
        0x8cc70208,
        0x90befffa,
        0xa4506ceb,
        0xbef9a3f7,
        0xc67178f2,
};

void memswap(void *a, void *b, size_t size)
{
    size_t i;

    i = -1;
    while (++i < size)
    {
        if (((char *)a)[i] != ((char *)b)[i])
        {
            ((char *)a)[i] ^= ((char *)b)[i];
            ((char *)b)[i] ^= ((char *)a)[i];
            ((char *)a)[i] ^= ((char *)b)[i];
        }
    }
}

char *itoa_base(unsigned long long value, int base, size_t out_len)
{
    int i;
    char *nbr;

    if (!(nbr = (char *)malloc(sizeof(nbr) * out_len)))
        return (NULL);
    memset(nbr, '0', out_len);
    nbr[out_len] = '\0';
    i = out_len;
    while (i-- > 0)
    {
        nbr[i] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
        value = value / base;
    }
    return (nbr);
}

unsigned char *pad_message(unsigned char *message, size_t byte_len, size_t *padded_len, size_t block_size, size_t len_size)
{
    unsigned char *padded;

    *padded_len = byte_len * 8 + 1;
    while (*padded_len % block_size != block_size - len_size)
        (*padded_len)++;
    *padded_len /= 8;
    if (!(padded = (unsigned char *)malloc(sizeof(unsigned char) * (*padded_len + (len_size / 8)))))
        return (NULL);
    memset(padded, 0x00, *padded_len);
    memcpy(padded, message, byte_len);
    padded[byte_len] = 0x80;
    byte_len *= 8;
    memcpy(padded + *padded_len, &byte_len, 8);
    return (padded);
}

unsigned char *format_hash(void *h, size_t tab_size, size_t format_size, size_t h_size)
{
    unsigned char *digest;
    char *tmp;
    size_t i;
    unsigned long long value;

    if (!(digest = (unsigned char *)malloc(sizeof(unsigned char) * (format_size + 1))))
        return (NULL);
    digest[format_size] = '\0';
    i = -1;
    while (++i < tab_size)
    {
        value = (h_size == 16) ? ((unsigned long *)h)[i] : ((unsigned int *)h)[i];
        if (!(tmp = itoa_base(value, 16, h_size)))
            return (NULL);
        memcpy(digest + i * h_size, tmp, h_size);
        free(tmp);
    }
    return (digest);
}

void buf_to_little_endian(void *data, size_t size)
{
    size_t i;

    i = 0;
    while (i < size / 2)
    {
        memswap(data + i, data + size - 1 - i, 1);
        ++i;
    }
}

static void fill_w(unsigned char *msg, unsigned int *w)
{
    int t;
    int i;

    t = 0;
    i = 0;
    while (t < 16)
    {
        w[t] = (msg[i + 0] << 24) | (msg[i + 1] << 16) | (msg[i + 2] << 8) | (msg[i + 3] << 0);
        i += 4;
        t++;
    }
    while (t < 64)
    {
        w[t] = SHA256_SIG1(w[t - 2]) + w[t - 7] + SHA256_SIG0(w[t - 15]) + w[t - 16];
        ++t;
    }
}

unsigned char *sha256(unsigned char *str, size_t size)
{
    unsigned char *padded;
    size_t padded_len;

    int h[8];
    unsigned int w[64];

    size_t i;
    unsigned int a, b, c, d, e, f, g, h_;
    unsigned int t, t1, t2;

    if (!(padded = pad_message(str, size, &padded_len, 512, 64)))
        return (NULL);
    buf_to_little_endian(padded + padded_len, 8);

    h[0] = 0xcbbb9d5d;
    h[1] = 0x629a292a;
    h[2] = 0x9159015a;
    h[3] = 0x152fecd8;
    h[4] = 0x67332667;
    h[5] = 0x8eb44a87;
    h[6] = 0xdb0c2e0d;
    h[7] = 0x47b5481d;

    i = -1;
    while (++i * 64 < padded_len)
    {
        fill_w(padded + (i * 64), w);
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        h_ = h[7];
        t = -1;
        while (++t < 64)
        {
            t1 = h_ + SHA256_EP1(e) + CH(e, f, g) + k[t] + w[t];
            t2 = SHA256_EP0(a) + MAJ(a, b, c);
            h_ = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_;
    }
    free(padded);
    return (format_hash(h, 8, 64, 8));
}

int main()
{
    unsigned char message[151];
    scanf("%[^\n]", message);

    printf("%s\n", sha256((unsigned char *)message, strlen(message)));

    return 0;
}