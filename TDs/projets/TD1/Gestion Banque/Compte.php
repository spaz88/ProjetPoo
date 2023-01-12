<?php 

include 'Titulaire.php';

class Compte {

    private Titulaire $titulaire;
    private float $solde;
    private bool $aDecouvert;

    public function __construct($titulaire) {
        $this->titulaire = $titulaire;
        $this->aDecouvert = false;
        $this->solde = 0;
    }

    // Getter principaux 
    public function getTitulaire() : Titulaire {
        return $this->titulaire;
    }

    public function getSolde() : float {
        return $this->solde;
    }

    public function getStatusDecouvert() : void {
        if($this->solde < 0) {
            echo "Vous êtes à découvert";
        } else {
            echo "Tout va bien bb";
        }
    }

    // Setters principaux 
    public function setTitulaire($nom) : void {
        $this->titulaire = $nom;
    }

    public function setAdecouvert($status) : void {
        $this->aDecouvert = $status;
    }

    // Methodes exo 
    public function depot($montant) : void {
        $this->solde += $montant;
    }

    public function retrait($montant) : void {
        $this->solde -= $montant;
    } 

    public function virement($compteReception, $montant) {
        $this->retrait($montant);
        $compteReception->depot($montant);
    }

} 