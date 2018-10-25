	var canvas, ctx,mymapctx;
	var matrix;
	var WIDTH, HEIGHT,mymapWIDTH,mymapHEIGHT;
	var points = [];
	var mas;
	var running;
	var canvasMinX, canvasMinY;
	var POPULATION_SIZE;
	var CROSSOVER_PROBABILITY;
	var MUTATION_PROBABILITY;
	var pixelforpoints;
	var pixelforlines;
	var pixelforobstacles;
	var arrayGen;
	var arrayBestValue;
	var mutationTimes;
	var bestValue,worstValue, best,worst;
	var currentGeneration;
	var currentBest;
	var currentWorst;
	var population;
	var values;
	var counter = 0;
	var sizecounter = 1;
	var fitnessValues;
	var roulette;
	var scaleforroute = 1;
	var scale = 1;
	var worstr_a = 1.0;
	var bestr_a = 1.0;
	var poped = 0;
	var Sb,Sw,Tb,Tw;
	var xcanvas;
	var ycanvas;
	var xobstacles;
	var yobstacles;
	var allObstacles;
	var start,end,result = 0;
	var bestparentx;
	var bestparenty;
	var panX = 0;
	var panY = 0;
	var originx = 0;
	var originy = 0;
	var mouseDown = false;
	var startDragOffset = {};
	var myownMap = new Image();
	var currentMap = new Image();
	var V = 5;
	$(function() {
		init();
		initData();
		document.getElementById("floor").options[0].selected=true;
		document.getElementById("building").options[0].selected=true;
		$('#addRandom_btn').click(function() {
			if(!$("#floor option[value='0']:selected").val() && !$("#building option[value='']:selected").val() && counter>0){
				ctx.setTransform(1, 0, 0, 1, 0, 0);
				mymapctx.setTransform(1, 0, 0, 1, 0, 0);
				if (myownMap !=="") {
					mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
				mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				addRandomPoints(10);
				$('#status').text("");
				running = false;
			}
		});
		$('#start_btn').click(function() { 
			if(points.length >= 2) {
				console.clear();
				console.log("____________________________________________________________________________________________________________________________________________________________________________");
				console.log("Поколение\u0020|"+"Лучший маршрут\u0020|"+"\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020Кандидаты на селекцию\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020|Кандидаты на скрещивание|");
				worstr_a = 1.0;
				bestr_a = 1.0;
				initData();
				GAInitialize();
				running = true;
			} else {
				alert("На карте должно быть не менее 2 точек обхода!");
			}

		});
		$('#bestroute').click(function(){
			if (worstr_a === 1.0) {
				worstr_a = 0;
			} else bestr_a =1.0;
		});
		$('#worstroute').click(function(){
			if (bestr_a === 1.0) {
				bestr_a = 0;
			} else worstr_a=1.0;
		});
		$('#exit_btn').click(function(){
			exitCanvas();
		});
		$('#clear_btn').click(function() {
			running === false;
			initData();
			points = new Array();
		});
	});
	function drawCanvasstruct() {
		canvas = document.getElementById("myCanvas"),
		ctx = canvas.getContext("2d"),
		canvas = document.getElementById("myMap"),
		mymapctx  = canvas.getContext('2d');
		ctx.save();
		//ctx.scale(scale,scale);
		//mymapctx.scale(scale,scale);
		if(window.innerWidth<=1305)
		{
			WIDTH = ctx.canvas.width  = window.innerWidth/2;
			mymapWIDTH = mymapctx.canvas.width  = window.innerWidth/2;
			if(window.innerHeight<=654)
			{
				HEIGHT =ctx.canvas.height = window.innerHeight/1.21;
				mymapHEIGHT = mymapctx.canvas.height = window.innerHeight/1.21;
			}
			else{
				HEIGHT =ctx.canvas.height = window.innerHeight/1.24;
				mymapHEIGHT = mymapctx.canvas.height = window.innerHeight/1.24;
			}
		}
		else if (window.innerWidth>1800)
			{	WIDTH = ctx.canvas.width  = window.innerWidth/1.83;
				mymapWIDTH = mymapctx.canvas.width  = window.innerWidth/1.83;
				if(window.innerHeight<=950){
					HEIGHT = ctx.canvas.height = window.innerHeight/1.76;
					mymapHEIGHT = mymapctx.canvas.height = window.innerHeight/1.76;
				}
				else
				{
					HEIGHT = ctx.canvas.height = window.innerHeight/1.79;
					mymapHEIGHT = mymapctx.canvas.height = window.innerHeight/1.79;	
				}
			}
		}
		function init() {
			window.onload = function(){	
				drawCanvasstruct();

				init_mouse();
				setInterval(draw,10);
			}
		}
		function init_mouse() {
			var mapher1f = new Image();
			var mapher2f = new Image();
			var mapher3f = new Image();
			mapher1f.src = "images/hermitage1f.png";
			mapher2f.src = "images/hermitage2f.png";
			mapher3f.src = "images/hermitage3f.png";

			$("#myCanvas").dblclick(function(evt) {
				if(!$("#floor option[value='0']:selected").val() && !$("#building option[value='0']:selected").val() && counter>0){
					if(points.length >=100){
						alert("Превышен лимит в 100 токек!");
					}
					if(!running && points.length <100) {
						canvasMinX = $("#myCanvas").offset().left;
						canvasMinY = $("#myCanvas").offset().top;
						$('#status').text("");
						x = evt.pageX - canvasMinX;
						y = evt.pageY - canvasMinY;	
						pixelforpoints = mymapctx.getImageData(x,y, WIDTH,HEIGHT).data;
						if ((pixelforpoints[0] !=115 && pixelforpoints[1] !=105 && pixelforpoints[2] !=105)&& (pixelforpoints[0] >10 && pixelforpoints[1] >10 && pixelforpoints[2] >10)&& (pixelforpoints[0] !=191 && pixelforpoints[1] !=190 && pixelforpoints[2] !=190)){
							points.push(new Point(x, y));
						}
					}
				}
			});

			$('#plus').click(function() {
				sizecounter = sizecounter +0.25;
				if (sizecounter >2) {
					scale = 1;
					sizecounter = 2;
				}
				else scale = 1.25;
				ctx.scale(scale,scale);
				mymapctx.scale(scale,scale);
				if (myownMap !=="") {
					mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
				mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				ctx.save();
				mymapctx.save();
			});
			$('#minus').click(function() {
				sizecounter = sizecounter - 0.25;
				if (sizecounter <=1) {
					sizecounter = 1;
					scale = 1;
					ctx.setTransform(1, 0, 0, 1, 0, 0);
					mymapctx.setTransform(1, 0, 0, 1, 0, 0);
				} else scale = 0.75;
				ctx.scale(scale,scale);
				mymapctx.scale(scale,scale);
				if (myownMap !=="") {
					mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
				mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
			});
			$('#fit').click(function(){
				ctx.clearRect(0, 0, WIDTH, HEIGHT);
				mymapctx.clearRect(0,0,mymapWIDTH,mymapHEIGHT);
				ctx.setTransform(1, 0, 0, 1, 0, 0);
				mymapctx.setTransform(1, 0, 0, 1, 0, 0);
				sizecounter = 1;
				if (myownMap !=="") {
					mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
				mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
			});
			$('#uparrow').click(function(){
				if (scale !== 1.0) {
					panX = 0;
					panY =0;
					panY += 50;
					ctx.clearRect(0, 0, WIDTH, HEIGHT);
					mymapctx.clearRect(0,0,mymapWIDTH,mymapHEIGHT);
					ctx.translate(panX,panY);
					mymapctx.translate(panX,panY);
					if (myownMap !=="") {
						mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
					}
					mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
			});
			$('#downarrow').click(function(){
				if (scale !== 1.0) {
					panX = 0;
					panY =0;
					panY -= 50;
					ctx.clearRect(0, 0, WIDTH, HEIGHT);
					ctx.translate(panX,panY);
					mymapctx.clearRect(0,0,mymapWIDTH,mymapHEIGHT);
					mymapctx.translate(panX,panY);
					if (myownMap !=="") {
						mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
					}
					mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
			});
			$('#rightarrow').click(function(){
				if (scale !== 1.0) {
					panX = 0;
					panX -= 50;
					panY = 0;
					ctx.clearRect(0, 0, WIDTH, HEIGHT);
					ctx.translate(panX,panY);
					mymapctx.clearRect(0,0,mymapWIDTH,mymapHEIGHT);
					mymapctx.translate(panX,panY);
					if (myownMap !=="") {
						mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
					}
					mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
			});
			$('#leftarrow').click(function(){
				if (scale !== 1.0) {
					panX = 0;
					panX += 50;
					panY =0;
					ctx.clearRect(0, 0, WIDTH, HEIGHT);
					ctx.translate(panX,panY);
					mymapctx.clearRect(0,0,mymapWIDTH,mymapHEIGHT);
					mymapctx.translate(panX,panY);
					if (myownMap !=="") {
						mymapctx.drawImage(myownMap, 0, 0,(myownMap.width),(myownMap.height),0,0,mymapWIDTH,mymapHEIGHT);
					}
					mymapctx.drawImage(currentMap, 0, 0,(currentMap.width),(currentMap.height),0,0,mymapWIDTH,mymapHEIGHT);
				}
			});
			$('#buttonLegend').click(function() {
				var $this = $(this);
				$this.toggleClass('buttonLegend');
				if($this.hasClass('buttonLegend')){
					if($("#floor option[value='1']:selected").val() && $("#building option[value='1']:selected").val() && $this.text("Скрыть легенду")){
						$("#legendframe1f").hide();
						$this.text("Показать легенду");
						$("#control_buttons").show();
					}
					else if ($("#floor option[value='2']:selected").val() && $("#building option[value='1']:selected").val() && $this.text("Скрыть легенду")){
						$("#legendframe2f").hide();
						$this.text("Показать легенду");
						$("#control_buttons").show();
					}
					else if ($("#floor option[value='3']:selected").val() && $("#building option[value='1']:selected").val() && $this.text("Скрыть легенду")){
						$("#legendframe3f").hide();
						$this.text("Показать легенду");
						$("#control_buttons").show();	
					} else alert("Пожалуйста выберите этаж и здание!");

				} else {
					if($("#floor option[value='1']:selected").val() && $("#building option[value='1']:selected").val() && $this.text("Показать легенду")){
						$("#legendframe1f").show();
						$this.text("Скрыть легенду");
						$("#control_buttons").hide();
					}
					else if ($("#floor option[value='2']:selected").val() && $("#building option[value='1']:selected").val() && $this.text("Показать легенду")){
						$("#legendframe2f").show();
						$this.text("Скрыть легенду");
						$("#control_buttons").hide();	
					}
					else if ($("#floor option[value='3']:selected").val() && $("#building option[value='1']:selected").val() && $this.text("Показать легенду")){
						$("#legendframe3f").show();
						$this.text("Скрыть легенду");
						$("#control_buttons").hide();	
					}
					else alert("Пожалуйста выберите этаж и здание!");
				}
			});
			$('.ombtn').click(function(e){
				e.preventDefault();
				$('#file').click();
				var fileInput = document.getElementById('file');
				$('#file').change(function(){
					myownMap.src = "images/"+fileInput.files[0].name;
					document.getElementById("floor").options[0].selected=true;
					document.getElementById("building").options[0].selected=true;

				});   
			});
			$('.mbtn').click(function() {
				ctx.setTransform(1, 0, 0, 1, 0, 0);
				mymapctx.setTransform(1, 0, 0, 1, 0, 0);
				counter = counter+1;
				scaleformap = 1.0;
				scale = 1.0;
				running === false;
				initData();
				points = new Array();
				panX = 0;
				panY =0;
				$("#legendframe1f").hide();
				$("#legendframe2f").hide();
				$("#legendframe3f").hide();
				$("#control_buttons").show();
				$("#buttonLegend").text("Показать легенду");
				if($("#floor option[value='1']:selected").val() && $("#building option[value='1']:selected").val()){
					myownMap.src = "";
					mymapctx.drawImage(mapher1f, 0, 0,mapher1f.width,mapher1f.height,0,0,mymapWIDTH,mymapHEIGHT);
					mymapctx.translate(panX,panY);
					currentMap.src ="images/hermitage1f.png";

					//blackCounter();
				}
				else if ($("#floor option[value='2']:selected").val() && $("#building option[value='1']:selected").val()){
					panX = 0;
					panY =0;
					myownMap.src ="";
					mymapctx.translate(panX,panY);
					mymapctx.drawImage(mapher2f, 0, 0,mapher2f.width,mapher2f.height,0,0,mymapWIDTH,mymapHEIGHT);
					currentMap.src ="images/hermitage2f.png";
					//blackCounter();
				}
				else if ($("#floor option[value='3']:selected").val() && $("#building option[value='1']:selected").val()){
					myownMap.src = "";
					mymapctx.drawImage(mapher3f, 0, 0,mapher3f.width,mapher3f.height,0,0,mymapWIDTH,mymapHEIGHT);
					currentMap.src ="images/hermitage3f.png";
      			//blackCounter();
      		}
      		else if (myownMap.src !== ""){
      			mymapctx.drawImage(myownMap, 0, 0,myownMap.width,myownMap.height,0,0,mymapWIDTH,mymapHEIGHT);
      			currentMap.src ="";
      			var imageData = mymapctx.getImageData(0,0,WIDTH,HEIGHT);
      			//blackCounter();
      		}
      		else alert("Пожалуйста выберите этаж и здание!"); 
      	});
		}
		function initData() {
			running = false;
			POPULATION_SIZE = 10;
			ELITE_RATE = 0.3;
			CROSSOVER_PROBABILITY = 0.9;
			MUTATION_PROBABILITY  = 0.01;
			UNCHANGED_GENS = 0;
			mutationTimes = 0;
			bestValue = undefined;
			worstValue = undefined;
			best = [];
			worst = [];
			currentGeneration = 0;
			currentBest;
			currentWorst;
			population = []; 
			arrayGen = new Array();
			arrayBestValue = new Array();
			values = new Array(POPULATION_SIZE);
			fitnessValues = new Array(POPULATION_SIZE);
			roulette = new Array(POPULATION_SIZE);
			xobstacles;
			yobstacles;
			mas = new Array();
			xcanvas = new Array();
			ycanvas = new Array();
			allObstacles = new Array();
		}
		function addRandomPoints(number) {
			running = false;
			for(var i = 0; i<number; i++) {
				if(points.length >=100){
					alert("Превышен лимит в 100 точек!");
					break;
				} 
				else {
					x = (Math.random()*WIDTH)+0;
					y = (Math.random()*HEIGHT)+0;
					pixelforpoints = mymapctx.getImageData(x,y, WIDTH,HEIGHT).data;	
					if ((pixelforpoints[0] !=115 && pixelforpoints[1] !=105 && pixelforpoints[2] !=105)&& (pixelforpoints[0] >60 && pixelforpoints[1] >60 && pixelforpoints[2] >60)&& (pixelforpoints[0] !=191 && pixelforpoints[1] !=190 && pixelforpoints[2] !=190)){
						points.push(new Point(x,y));
					}
					if (points.length <100){
						return addRandomPoints(number);
					} 
				}
			}
		}
		function drawCircle(point) {
			ctx.beginPath();
			ctx.arc(point.x, point.y, 4, 0, Math.PI*2, true);
			ctx.closePath();
			ctx.fill();
		}
		function drawLines(array) {
			//blackCounter();
			ctx.lineWidth = 4;
			var imageData = mymapctx.getImageData(0,0,WIDTH,HEIGHT);
			var data = imageData.data;
			ctx.beginPath();
			ctx.moveTo(points[array[0]].x, points[array[0]].y);
			for(var i=1; i<array.length; i++) {
				ctx.lineTo(points[array[i]].x, points[array[i]].y)
			}
			ctx.lineTo(points[array[0]].x, points[array[0]].y);
			ctx.stroke();
			ctx.closePath();
		}
		function draw() {
			start =  new Date().getTime();

			if(running) {
				GANextGeneration();
				end = (new Date().getTime() - start);
				result = result + end*1.6;
				$('#status').html("На карте " + points.length + " точек, "+ currentGeneration + "-е поколение "+'<br />'+ "Лучший путь: "+ ~~(bestValue)+" м "+'<br />'+"Худший путь: " + ~~(worstValue)+" м "+'<br />'+"Время работы программы: "+result.toFixed(1)/100+" сек ");
			} else {
				$('#status').text("На карте " + points.length + " точек. ");
				if(bestValue!== undefined){
					if(worstValue === undefined){worstValue=bestValue;}
					Sb = (bestValue), Tb = (Sb/1000/V)*60, Sw = (worstValue),Tw = (Sw/1000/V)*60;
					$('#status').html("Количество точек: "+points.length+'<br />'+"Оптимальный путь: "+Sb+" м ,"+" Время: "+Tb.toFixed(0)+" мин "+'<br />'+"Худший путь: "+Sw+" м ,"+" Время: "+Tw.toFixed(0)+" мин "+'<br />'+"Текущее поколение: "+(currentGeneration)+'<br />'+"Время работы программы: "+(result.toFixed(1)/100)+" сек ");
				} else result = 0;
			}
		//result = 0;
		clearCanvas();
		WorstRoute();
		BestRoute();
	}
	function BestRoute(){
		ctx.strokeStyle = 'rgba(255,255,255,'+bestr_a+')';
		if (points.length > 0 ){
			for (var i=0;i<points.length;i++){
				ctx.fillStyle = '#f00';
				drawCircle(points[i]);
			}
			for(var i=1; i<points.length; i++) {
				ctx.fillStyle = '#0f0';
				drawCircle(points[i]);
			}
			if(best.length === points.length) {
				drawLines(best);
			}
		}
	}
	function WorstRoute(){
		ctx.strokeStyle = 'rgba(0,0,0,'+worstr_a+')';
		if (points.length > 0 ){
			for (var i=0;i<points.length;i++){
				ctx.fillStyle = '#f00';
				drawCircle(points[i]);
			}
			for(var i=1; i<points.length; i++) {
				ctx.fillStyle = '#0f0';
				drawCircle(points[i]);
			}
			if(worst.length === points.length) {
				drawLines(worst);
			}
		}
	}
	function clearCanvas() {
		ctx.clearRect(0, 0, WIDTH, HEIGHT);
	}
	function exitCanvas(){
		if (confirm("Вы действительно хотите закрыть окно?")) {
			close();
		}
	}
	function reloadCanvas(){
		location.reload();
	}