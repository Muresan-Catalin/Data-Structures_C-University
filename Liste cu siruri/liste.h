#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

typedef struct {
    int *storage;
    int maxlength;
    int last;
} t_lista;

void MakeNull(t_lista *lista);
void Destroy(t_lista *lista);

#endif // LISTE_H_INCLUDED
