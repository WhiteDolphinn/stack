#ifndef STEK_H
#define STEK_H
#define SIZE 15
struct stek{
int data[SIZE];
int depth;
};
struct stek stek_start();
void input_commands();
void stek_push(struct stek* stek, int i);
void stek_add(struct stek* stek);
void stek_print(struct stek* stek);
int stek_test(struct stek* stek);
#endif
