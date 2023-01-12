<?php

include 'CCommercial.php';
include 'CManutentionnaire.php';
include 'CTechnicien.php';

class CPersonnel {

    private $membres;

    public function __construct() {
        $this->membres = array();
    }

    public function __desctruct() { }

    // Méthodes classes 

    // Simple push en array
    public function embaucher(CEmploye $new) : void {
        array_push($this->membres, $new);
    }

    // On trouve l'employé parmis les membres, et on le supprime s'il existe bien
    public function licencier(CEmploye $old) : void {
        $find_one = array_search($old, $this->membres , true);
        if($find_one) {
            unset($this->membres[$find_one]);
        }
    }

    public function faillite() : void {
        // Y a bcp de manière de la faire, j'ai choisi la simplicité
        $this->membres = array();
    }


    // Liste et affichage 
    public function printSalaire() : void {
        foreach($this->membres as $membre) {
            echo $membre->employe() . " : ";
            echo $membre->calculSalaire();
            echo "<br/>";
        }
    }

    // Calcul du salaire moyen en reprennant tous les employés 
    public function salaireMoyen() : void {
        $nb = count($this->membres);
        $salaires = 0;

        foreach($this->membres as $membre) {
            $salaires += $membre->calculSalaire();
        }

        $salaires = $salaires / $nb;

        echo "Salaire moyen : " . $salaires;
    }


}