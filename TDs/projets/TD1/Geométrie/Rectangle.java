package geometrie;

public class Rectangle extends Polygone {
	
	protected String type;
	protected float cote1;
	protected float cote2;
	protected float cote3;
	protected float cote4;

	public float getCote1() {
		return cote1;
	}

	public void setCote1(float cote1) {
		this.cote1 = cote1;
	}

	public float getCote2() {
		return cote2;
	}

	public void setCote2(float cote2) {
		this.cote2 = cote2;
	}

	public float getCote3() {
		return cote3;
	}

	public void setCote3(float cote3) {
		this.cote3 = cote3;
	}

	public float getCote4() {
		return cote4;
	}

	public void setCote4(float cote4) {
		this.cote4 = cote4;
	}

	public void setType(String type) {
		this.type = type;
	}
	
	public Rectangle() {
		this.cote1 = 0;
		this.cote2 = 0;
		this.cote3 = 0;
		this.cote4 = 0;
		this.type = "Rectangle";
	}
	
	public Rectangle(float cote1, float cote2, float cote3, float cote4, String type){
		this.cote1 = cote1;
		this.cote2 = cote2;
		this.cote3 = cote3;
		this.cote4 = cote4;
		this.type = type;
	}

	public float calculAire(){
		float aire=cote1;
		
		if(aire != cote2) {
			aire = aire*cote2;
		} 
		else if(aire != cote3) {
			aire = aire*cote3;
		} 
		else {
			aire = aire*cote4;
		}
		return aire;
	}
	
	public float calculPerimetre() {
		return cote1+cote2+cote3+cote4;
	}
	
	public String monType() {
		return type + "-->" + super.monType();
	}
}
