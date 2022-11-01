#ifndef STEK_H
#define STEK_H
#define SIZE 15
typedef int stek_type;
struct stek{
stek_type *data;
int depth;
};
void stek_init(struct stek* stek);
void input_commands();
void stek_push(struct stek* stek, int i);
void stek_add(struct stek* stek);
void stek_print(struct stek* stek);
int stek_test(struct stek* stek);
#endif
