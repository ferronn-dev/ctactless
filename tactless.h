#ifndef TACTLESS_H_
#define TACTLESS_H_

#include <stddef.h>
#include <stdint.h>

struct tactless;
typedef struct tactless tactless;

tactless *tactless_open(const char *product);
void tactless_close(tactless *t);
void tactless_dump(const tactless *t);

struct tactless_root_fdids {
  int32_t fdid;
  unsigned char ckey[16];
};

struct tactless_root_names {
  unsigned char name[8];
  int32_t fdid;
};

struct tactless_root {
  size_t num_fdids;
  struct tactless_root_fdids *fdids;
  size_t num_names;
  struct tactless_root_names *names;
};

int tactless_root_parse(const unsigned char *s, size_t n,
                        struct tactless_root *r);
void tactless_root_dump(const struct tactless_root *r);
void tactless_root_free(struct tactless_root *r);

struct tactless_encoding {
  unsigned char *data;
  int n;
};

int tactless_encoding_parse(const unsigned char *s, size_t n,
                            struct tactless_encoding *e);
void tactless_encoding_dump(const struct tactless_encoding *e);
void tactless_encoding_free(struct tactless_encoding *e);

struct tactless_archive_index {
  unsigned char name[16];
  unsigned char *data;
  size_t n;
};

int tactless_archive_index_parse(const unsigned char *s, size_t n,
                                 struct tactless_archive_index *a);
void tactless_archive_index_dump(const struct tactless_archive_index *a);
void tactless_archive_index_free(struct tactless_archive_index *a);

unsigned char *tactless_readfile(const char *filename, size_t *size);

#endif
