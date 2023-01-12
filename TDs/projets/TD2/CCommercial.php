<?php 

include_once 'CEmploye.php';

class CCommercial extends CEmploye {

    const PART = 15;
    private float $m_chiffreAffaire;
    const BASE = 110;

    public function __construct($nom, $prenom, $age, $anc, $ca) {
        parent::__construct($nom,$prenom,$age,$anc);
        $this->m_chiffreAffaire = $ca;
    }

    public function calculBaseSalaire() : float {
        return self::PART * $this->m_chiffreAffaire + self::BASE;
    }
}