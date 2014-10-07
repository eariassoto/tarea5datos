//ejemplo convertir a JSON
var parseToJSON = function(str){
    return JSON.parse(str);    
}

//ejemplo convertir de JSON
var parseFromJSON = function(json){
	return JSON.stringify(json);
}

/** Clase Coordenadas **/
function Coordenadas(dimensionCanvas, numNodos, nodosFinales) { 
	this.dimensionCanvas = dimensionCanvas;
	this.numNodos = numNodos;
	this.nodosFinales = nodosFinales;
	this.radio = (this.dimensionCanvas*0.8)/2;
    this.angulo = (2*Math.PI)/this.numNodos;
}

///numDeDodo es el nodo que quiero calcular (0,1,2,3...etc), primero calculando los puntos de su circunferencia
Coordenadas.prototype.calcularCoordenadaNodo = function (numDeNodo) { 
	px = this.radio * Math.cos(numDeNodo * this.angulo);
    py = this.radio * Math.sin(numDeNodo * this.angulo);
    
    // con estas varriales se calculan las coordenadas reales
    
    coordX = (this.dimensionCanvas/2)+px;
    coordY = (this.dimensionCanvas/2)-py;
    
    return [coordX, coordY];
}

///Modifica el dato del indice deseado
Coordenadas.prototype.calcularCoordenadas = function () { 
	radioCirculo = Math.round((this.radio/this.numNodos)*0.45);
    var coordenadas = [];
    for(i = 0; i < this.numNodos; i++){
    	
    	if($.inArray( i, this.nodosFinales ) != -1)
    		color = 1;
    	else
    		color = 0;

	    anguloInclinacion = i * this.angulo;        
	    var1 = this.calcularCoordenadaNodo(i);
	    var obj = new Object();
	    obj.coordX = Math.round(var1[0]);
	    obj.coordY = Math.round(var1[1]);
	    obj.radio = radioCirculo;
	    obj.color = color;
	    obj.angulo = anguloInclinacion;
	    coordenadas.push(obj);
	}

	return coordenadas;
}
/**Fin clase Coordenadas**/

/** Clase Circulo **/
function Circulo(r, cx, cy){
	this.radio = r;
    this.coordX = cx;
    this.coordY = cy;
}

Circulo.prototype.generarSVG = function(){
    return '<circle cx="'+this.coordX+'" cy="'+this.coordY+'" r="'+this.radio+'" fill="red"/>';
}

/** Fin clase Circulo **/

/** Clase SVG **/
function SVG(largo){
    this.preSvg = '<svg width="'+largo+'px" height="'+largo+'px" style="stroke-width: 0px; background-color: green;">';
    this.posSvg = '</svg>';
    this.contenido = "";
}

SVG.prototype.agregarElemento = function(elem){
    this.contenido += elem.generarSVG();
}

SVG.prototype.generarSVG = function(){
    return $(this.preSvg + this.contenido + this.posSvg);
}
/** Fin clase SVG **/

/** Manejo eventos botones / php **/
function validate(){
 	input = $("#txtInput").val();
	if(input != ""){
	
		//funcion AJAX es.wikipedia.org/wiki/AJAX que interactua con el php 
		$.ajax({
			type: "POST",
			url: "/intermediario.php",
			data: {validarHilera: input},
			dataType:'JSON', 
			success: function(response){
				//usa jquery para agregar al final de una etiqueta la respuesta.
				$( "#results" ).append( "<p>"+response.resp+"</p>" );
			}
		});
	}
 }
		 
 function obtenerGrafo(){
	$.ajax({
		type: "POST",
		url: "/intermediario.php",
		data: {obtenerGrafo: "-g"},
		dataType:'JSON', 
		success: function(response){
			var grafo = parseToJSON(response.resp);
			console.log(grafo);
			var coor = new Coordenadas(600, grafo.numNodos, grafo.nodosFinales);
			console.log(coor.calcularCoordenadas());

			var circ1 = new Circulo(20, 50, 50);
			var circ2 = new Circulo(20, 140, 50);
			var circ3 = new Circulo(20, 230, 50);

			var mySVG = new SVG(600);
			mySVG.agregarElemento(circ1);
			mySVG.agregarElemento(circ2);
			mySVG.agregarElemento(circ3);

			var svgElement = mySVG.generarSVG();
			$("#divSVG").append(svgElement);
		}
	});
 }

 /** Fin manejo eventos botones / php **/
 