public class estagiario extends funcionario{
  private double valecoxinha;

  public estagiario(int ID, String nome, int departamento, double salario, double valecoxinha){
    super(ID, nome, departamento, salario, 0);
    this.valecoxinha = valecoxinha;
  }

  void setValeCoxinha( double valecoxinha ){
    this.valecoxinha = valecoxinha;
  }
  double pagamento(){
    // Calcula o salário líquido
    return(getSalario()+this.valecoxinha);
  }

}