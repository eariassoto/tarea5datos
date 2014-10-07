<?php
	//escucha los eventos, procesa la ejecucion y envía respuesta
    if(isset($_POST['validarHilera']) && !empty($_POST['validarHilera'])) {
		$data=$_POST['validarHilera'];
		exec("automataHileras.exe automata.txt ".$data,$output);
		
		//implode une los arrays
		$res = implode("", $output);
		echo json_encode(array("resp"=>"$res"));
		
    }else if(isset($_POST['obtenerGrafo']) && !empty($_POST['obtenerGrafo'])) {
		$data=$_POST['obtenerGrafo'];
		exec("automataHileras.exe automata.txt ".$data,$output);
		
		//implode une los arrays
		$res = implode("", $output);
		echo json_encode(array("resp"=>"$res"));
		
    }
?>
