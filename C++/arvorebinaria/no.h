#ifndef NO_H
#define NO_H

class No{
  private:
    No *esq, *dir, *pai;
    int chave;
  public:
    No(int chave);
    int getChave();
    No* getEsq();
    No* getDir();
    No* getPai();
    void setEsq(No *no);
    void setDir(No *no);
    void setPai(No *no);
};

#endif