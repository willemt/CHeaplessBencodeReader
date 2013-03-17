#pragma once

typedef struct
{
    const char *str;
    const char *start;
    void *parent;
    int val;
    int len;
} bencode_t;

void bencode_init(
    bencode_t * be,
    const char *str,
    int len
);

bool bencode_is_int(
    bencode_t * be
);

void bencode_done(
    bencode_t * be
);

bool bencode_is_string(
    bencode_t * be
);

int bencode_int_value(
    bencode_t * be,
    long int *val
);

bool bencode_dict_has_next(
    bencode_t * be
);

int bencode_dict_get_next(
    bencode_t * be,
    bencode_t * be_item,
    const char **key,
    int *klen
);

int bencode_string_value(
    bencode_t * be,
    const char **str,
    int *len
);

bool bencode_list_has_next(
    bencode_t * be
);

int bencode_list_get_next(
    bencode_t * be,
    bencode_t * be_item
);

bool bencode_is_list(
    bencode_t * be
);

bool bencode_is_dict(
    bencode_t * be
);

void bencode_clone(
    bencode_t * be,
    bencode_t * output
);

/**
 * get the start and end position of this dictionary
 * @param start : starting string
 * @parama len : len of the dictionary */
int bencode_dict_get_start_and_len(
    bencode_t * be,
    const char **start,
    int *len
);

