public class empresa{
  
    private int numeroDeFuncionarios = 0;
    private int numero = 100;
    private funcionario container[] = new funcionario[this.numero];
  
  
    public void adicionarFuncionario(funcionario funcionario){
      this.container[numeroDeFuncionarios] = funcionario;
      this.numeroDeFuncionarios += 1;
    }
    
    public void calculaPagamento(int idFuncionario){
      for(int i = 0; i < numeroDeFuncionarios; i++){
        if(container[i].getID() == idFuncionario){
          System.out.println(container[i].pagamento());
        }
      }
    }
  
    public void aumentarAdicional(double adicional){
      for(int i = 0; i < numeroDeFuncionarios; i++){
        container[i].setAdicional(adicional);
      }
    }
  
    public void relatorioFuncionarios(){
      for(int i = 0; i < numeroDeFuncionarios; i++){
        System.out.println("ID: "+container[i].getID()+"  Nome: "+container[i].getNome()+"  Salario: "+container[i].getSalario());
      }
  
    }
  }