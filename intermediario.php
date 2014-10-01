<?php
	
    if(isset($_POST['action']) && !empty($_POST['action'])) {
		$data=$_POST['action'];
		exec("main.exe ".$data,$output);
		
		$res = implode("", $output);
		echo json_encode(array("resp"=>"$res"));
		
    }
?>
