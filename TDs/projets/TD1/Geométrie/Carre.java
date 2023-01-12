package geometrie;

public class Carre extends Rectangle{
    protected String type;
    protected float cote1;
    protected float cote2;
    
    public float getCote1(){
        return cote1;
    }
    
    public float setCote1(){
        this.cote1 = cote1;
    }
    
    public float getCote2(){
        return cote2;
    }
    
    public float setCote2(){
        this.cote2 = cote2;
    }
    
    public void setType(String type){
        this.type = type;
    }
    
    public Carre(){
        this.cote1 = 0;
        this.cote2 = 0;
        this.type = "Carré";
    }
    
    public Carre(float cote1, float cote2, String type){
        this.cote1 = cote1;
        this.cote2 = cote2;
        this.type = type;
    }
    
    public float calculAire(){
		return cote1*cote2;
	}
	
	public float calculPerimetre() {
		return cote1*2+cote2*2;
	}
	
	public String monType() {
		return type + "-->" + super.monType();
	}
}