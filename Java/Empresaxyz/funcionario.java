public class funcionario
{
    private int ID ;
    private String nome;
    private int departamento;
    private double salario, previdencia, adicional;

    public funcionario(int ID, String nome, int departamento, double salario, double adicional){
      this.ID = ID;
      this.nome=nome;
      this.departamento= departamento;
      this.salario= salario;
      this.previdencia=0.05; // Desconto fixo de um sistema de previdência da empresa
      this.adicional = adicional; // adicional caso o funcionário seja por exemplo chefe.
    }

    double pagamento(){
      // Calcula o salário líquido
      return (salario*((1-this.previdencia)+this.adicional));
    }

    void setID(int ID){
      this.ID = ID;
    }
    int getID(){
      return this.ID;
    }

    void setNome(String nome){
      this.nome=nome;
    }

    String getNome(){
      return this.nome;
    }

    void setDepartamento(int departamento){
      this.departamento= departamento;
    }

    int getDepartamento(){
      return this.departamento;
    }

    void setSalario(double salario){
      this.salario= salario;
    }
    double getSalario(){
      return this.salario;
    }

    double getPrevidencia(){
      return this.previdencia;
    }

    void setAdicional(double novo_percentual){
      this.adicional = adicional*(1+novo_percentual);
    }
    double getAdicional(){
      return this.adicional;
    }

}