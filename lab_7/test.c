#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STR_LEN 64

typedef struct Vector {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Vector;

typedef struct Person {
    int age;
    char first_name[MAX_STR_LEN];
    char last_name[MAX_STR_LEN];
} Person;

// Allocate vector to initial capacity (block_size elements),
// Set element_size, size (to 0), capacity
void init_vector(Vector *vector, size_t block_size, size_t element_size) {
    vector -> data = malloc(block_size * element_size);
    vector -> element_size = element_size;
    vector -> size = 0;
    vector -> capacity = block_size * element_size;
}

// If new_capacity is greater than the current capacity,
// new storage is allocated, otherwise the function does nothing.
void reserve(Vector *vector, size_t new_capacity) {
    if (new_capacity > vector -> capacity) {
        realloc(vector -> data, new_capacity);
    }
}

// Resizes the vector to contain new_size elements.
// If the current size is greater than new_size, the container is
// reduced to its first new_size elements.

// If the current size is less than new_size,
// additional zero-initialized elements are appended
void resize(Vector *vector, size_t new_size) {
    if (new_size > vector -> size) {
        reserve(vector, new_size * vector -> element_size);
        for( size_t size; size < new_size; size++) {
//            *(vector -> data + (vector -> element_size * size)) = 0;
        }
    }
}

// Add element to the end of the vector
void push_back(Vector *vector, void *value);

// Remove all elements from the vector
void clear(Vector *vector);

// Remove the last element from the vector
void pop_back(Vector *vector);

// Insert new element at index (0 <= index <= size) position
void insert(Vector *vector, int index, void *value);

// Erase element at position index
void erase(Vector *vector, int index);

// Erase all elements that compare equal to value from the container
void erase_value(Vector *vector, void *value, int(*cmp)(const void*, const void*));

// Erase all elements that satisfy the predicate from the vector
void erase_if(Vector *vector, int (*predicate)(void *));

// Request the removal of unused capacity
void shrink_to_fit(Vector *vector) {

}

// Print integer vector
void print_vector_int(Vector *vector);

// Print char vector
void print_vector_char(Vector *vector);

// Print vector of Person
void print_vector_person(Vector *vector);

// integer comparator - increasing order
int int_cmp(const void *v1, const void *v2);

// char comparator - lexicographical order (case sensitive)
int char_cmp(const void *v1, const void *v2);

// Person comparator:
// Sort according to age (decreasing)
// When ages equal compare first name and then last name
int person_cmp(const void *p1, const void *p2);

// predicate: check if number is even
int is_even(void *value);

// predicate: check if char is a vowel
int is_vowel(void *value);

// predicate: check if person is older than 25
int is_older_than_25(void *person);

// -------------------------------------------------------------

void read_int(void* value) {
    scanf("%d", (int*)value);
}

void read_char(void* value) {
    char c[2];
    scanf("%s", c);
    *(char*)value = c[0];
}

void read_person(void* value) {
    Person *person = (Person*)value;
    scanf("%d %s %s", &person->age, person->first_name, person->last_name);
}


int main(void) {
    int to_do, n;
    Vector vector_int, vector_char, vector_person;

    void* vector = malloc(3 * sizeof(int));
    printf("%d\n" ,vector);
    printf("%d" ,vector+1);
    return 0;
}