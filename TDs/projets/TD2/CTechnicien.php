<?php 

include_once 'CEmploye.php';

class CTechnicien extends CEmploye {

    private float $m_nbUniteProduite;

    const BASE = 130;
    const PART = 11;
    const GAIN_UNITE = 15;

    public function __construct($nom, $prenom, $age, $anc, $ca) {
        parent::__construct($nom,$prenom,$age,$anc);
        $this->m_nbUniteProduite = $ca;
    }

    public function calculBaseSalaire() : float {
        return self::BASE + $this->m_nbUniteProduite * self::PART * self::GAIN_UNITE;
    }
}