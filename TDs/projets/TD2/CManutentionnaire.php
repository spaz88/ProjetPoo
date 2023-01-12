<?php 

include_once 'CEmploye.php';

class CManutentionnaire extends CEmploye {

    private float $m_nbHeures = 0;

    const BASE_HORAIRE = 12;

    public function __construct($nom, $prenom, $age, $anc, $ca) {
        parent::__construct($nom,$prenom,$age,$anc);
        $this->m_nbHeures = $ca;
    }

    // On rédéfini la méthode de calculBaeSalaire
    public function calculBaseSalaire() : float {
        return self::BASE_HORAIRE * $this->m_nbHeures;
    }
}