package geometrie;

public class Triangle extends Polygone{
    
    protected String type;
	protected float cote1;
	protected float cote2;
	protected float cote3;
	
	public float getCote1(){
		return cote1;
	}

	public void setCote1(float cote1){
		this.cote1 = cote1;
	}

	public float getCote2(){
		return cote2;
	}

	public void setCote2(float cote2){
		this.cote2 = cote2;
	}

	public float getCote3(){
		return cote3;
	}

	public void setCote3(float cote3){
		this.cote3 = cote3;
	}

	public void setType(String type){
		this.type = type;
	}
	
	public Triangle(){
		this.cote1 = 0;
		this.cote2 = 0;
		this.cote3 = 0;
		this.type = "Triangle";
	}
	
	public Triangle(float cote1, float cote2, float cote3, String type){
		this.cote1 = cote1;
		this.cote2 = cote2;
		this.cote3 = cote3;
		this.type = type;
	}

	public float calculAire(){
		float demiPeri = (cote1 + cote2 + cote3)/2;
		return (float) Math.sqrt(demiPeri*(demiPeri-cote1)*(demiPeri-cote2)*(demiPeri-cote3));
	}
	
	public float calculPerimetre(){
		return cote1+cote2+cote3;
	}
	
	public String monType(){
		return type + "-->" + super.monType();
	}
}

}