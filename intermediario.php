<?php
	//escucha los eventos, procesa la ejecucion y envía respuesta
    if(isset($_POST['action']) && !empty($_POST['action'])) {
		$data=$_POST['action'];
		exec("automataHileras.exe automata.txt ".$data,$output);
		
		//implode une los arrays
		$res = implode("", $output);
		echo json_encode(array("resp"=>"$res"));
		
    }
?>
