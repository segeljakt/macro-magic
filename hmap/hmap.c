/******************************************************************************
*     File Name           :     src/hmap/hmap.c                               *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-06-30 21:58]                            *
*     Last Modified       :     [2017-06-21 22:12]                            *
*     Description         :     Hashmap implementation.                       *
******************************************************************************/
#include "./hmap.h"
#include <limits.h>  // ULONG_MAX
#include <strings.h> // strcasecmp
#include <stdio.h>
/*****************************************************************************/
typedef struct entry_s entry_t;
/*****************************************************************************/
struct hmap_s {
  entry_t **bucket;
  entry_t *head;
  size_t nmemb;
  size_t size;
};
/*---------------------------------------------------------------------------*/
struct entry_s {
  char *key;
  void *val;
  entry_t *left;
  entry_t *right;
  entry_t *next;
};
/*****************************************************************************/
static entry_t *new_entry(char *key, void *val);
static void free_entry(entry_t *entry);
static void unlink_entry(entry_t *entry);
static int hash(char *key);
/*****************************************************************************/
hmap_t *global_hmap = NULL;
/*****************************************************************************/
hmap_t *new_hmap(size_t size) {
  hmap_t *hmap = calloc(1, sizeof(hmap_t));
  hmap->bucket = calloc(1, sizeof(entry_t*)*size);
  hmap->size = size;
  return hmap;
}
/*---------------------------------------------------------------------------*/
void free_hmap(hmap_t *hmap, free_val_f free_val) {
  entry_t *bucket = hmap->head;
  while(bucket) { // For each bucket
    entry_t *entry = bucket;
    entry = entry->right;
    while(entry) { // Free all entries in bucket
      entry_t *free_ptr = entry;
      entry = entry->next;
      free_val(free_ptr->val);
      free_entry(free_ptr);
    }
  }
  free(hmap->bucket);
  free(hmap);
}
/*---------------------------------------------------------------------------*/
static entry_t *new_entry(char *key, void *val) {
  entry_t *entry = malloc(sizeof(entry_t));
  entry->key = strdup(key);
  entry->val = val;
  return entry;
}
/*---------------------------------------------------------------------------*/
static void free_entry(entry_t *entry) {
  free(entry->key);
  free(entry);
}
/*---------------------------------------------------------------------------*/
void *hmap_put(hmap_t *hmap, char *key, void *val) {
  if(val == NULL) {
    fprintf(stderr, "[ERROR]: Value put in hmap was NULL (key was %s)\n", key);
    abort();
  }
  int id = hash(key) % hmap->size; // Get hash value
  /* Find where entry should be put in bucket */
  entry_t **next = &hmap->bucket[id];
  int cmp_val = -1;
  while(*next != NULL && (cmp_val = strcasecmp(key, (*next)->key)) > 0) {
    next = &(*next)->next;
  }
  /* Entry already exists */
  if(cmp_val == 0) {
    return NULL;
  }
  /* Entry does not exist, create it and put it before next */
  entry_t *entry = new_entry(key, val);
  entry->next = *next;
  *next = entry;
  hmap->nmemb++;
  /* Configure queue */
  entry->right = hmap->head;
  if(hmap->head) {
    hmap->head->left = entry;
  }
  hmap->head = entry;
  return entry->val;
}
/*---------------------------------------------------------------------------*/
void *hmap_get(hmap_t *hmap, char *key) {
  int id = hash(key) % hmap->size;
  entry_t *entry = hmap->bucket[id];
  /* Find entry in bucket */
  int cmp_val = -1;
  while(entry != NULL && (cmp_val = strcasecmp(key, entry->key)) > 0) {
    entry = entry->next;
  }
  /* Entry exists */
  if(cmp_val == 0) {
    return entry->val;
  }
  /* Entry does not exist */
  return NULL;
}
/*---------------------------------------------------------------------------*/
void *hmap_getp(hmap_t *hmap, char *key) {
  int id = hash(key) % hmap->size;
  entry_t *entry = hmap->bucket[id];
  /* Find entry in bucket */
  int cmp_val = -1;
  while(entry != NULL && (cmp_val = strcasecmp(key, entry->key)) > 0) {
    entry = entry->next;
  }
  /* Entry exists */
  if(cmp_val == 0) {
    return &entry->val;
  }
  /* Entry does not exist */
  return NULL;
}
/*---------------------------------------------------------------------------*/
void *hmap_pop(hmap_t *hmap, char *key) {
  int id = hash(key) % hmap->size;
  entry_t **entry = &hmap->bucket[id];
  /* Find entry in bucket */
  int cmp_val = -1;
  while(*entry != NULL && (cmp_val = strcasecmp(key, (*entry)->key)) > 0) {
    entry = &(*entry)->next;
  }
  /* Entry exists */
  if(cmp_val == 0) {
    void *val = (*entry)->val;
    unlink_entry(*entry);
    entry_t *free_ptr = *entry;
    *entry = (*entry)->next;
    free_entry(free_ptr);
    hmap->nmemb--;
    return val;
  }
  /* Entry does not exist */
  return NULL;
}
/*---------------------------------------------------------------------------*/
void init_global_hmap(size_t size) {
  if(global_hmap == NULL) {
    new_hmap(size);
  }
}
/*---------------------------------------------------------------------------*/
static void unlink_entry(entry_t *entry) { // Unlink entry from linked list
  if(entry->left) {
    entry->left->right = entry->right;
  }
  if(entry->right) {
    entry->right->left = entry->left;
  }
}
/*---------------------------------------------------------------------------*/
static int hash(char *key) {
  int len = strlen(key);
  unsigned long int hashval = 0;
  int i = 0;
  for(i = 0; hashval < ULONG_MAX && i < len; i++) {
    hashval <<= 8;
    hashval += key[i];
  }
  return hashval;
}
