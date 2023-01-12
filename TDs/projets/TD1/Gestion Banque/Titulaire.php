<?php

class Titulaire {

    private string $nom;

    public function __construct($nom) {
        $this->nom = $nom;
    }

    public function getNom() : string {
        return $this->nom;
    }

    public function setNom($nom) : void {
        $this->nom = $nom;
    }

}