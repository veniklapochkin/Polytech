console.clear();
function GAInitialize() {
	countDistances(); 
	for(var i=0; i<POPULATION_SIZE; i++) {
		population.push(randomIndivial(points.length));
	}
	setBestandWorstValue();
}
function GANextGeneration() {
	currentGeneration++;
	arrayGen.push(currentGeneration);
	stopCriteria();
	console.log("_______________________________________________________________________________________________________________________________________________");
	console.log("|"+currentGeneration+"\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020|\u0020\u0020\u0020\u0020\u0020"+bestValue+"\u0020\u0020\u0020\u0020\u0020\u0020|"+values+"|"+"x: "+bestparentx+"|"+"y: "+bestparenty+"|");
  selection(); // отбор(селекция, новое поколение)
  crossover(); // скрещивание (размножение)
  mutation(); // мутация
  setBestandWorstValue();
}
function selection() {
	var parents = new Array();
	var initnum = 4;
	parents.push(population[currentBest.bestPosition]);
	parents.push(doMutate(best.clone()));
	parents.push(pushMutate(best.clone()));
	parents.push(best.clone());
	setRoulette();
	for(var i=initnum; i<POPULATION_SIZE; i++) {
		parents.push(population[wheelOut(Math.random())]);
	}
	population = parents;
}
function crossover() {
	var queue = new Array();
	for(var i=0; i<POPULATION_SIZE; i++) {
		if( Math.random() < CROSSOVER_PROBABILITY ) {
			queue.push(i);
		}
	} 
	queue.shuffle();
	for(var i=0, j=queue.length-1; i<j; i+=2) {
		doCrossover(queue[i], queue[i+1]);
	}
}
function doCrossover(x, y) {
	child1 = getChild('next', x, y);
	child2 = getChild('previous', x, y);
	population[x] = child1;
	population[y] = child2;
}
function getChild(fun, x, y) {
	solution = new Array();
	var px = population[x].clone();
	var py = population[y].clone();
	var dx,dy;
	var c = px[randomNumber(px.length)];
	solution.push(c);
	while(px.length > 1) {
		dx = px[fun](px.indexOf(c));
		dy = py[fun](py.indexOf(c));
		px.deleteByValue(c);
		py.deleteByValue(c);
		c = dis[c][dx] < dis[c][dy] ? dx : dy;
		solution.push(c);
	}
	return solution;
}
function mutation() {
	for(var i=0; i<POPULATION_SIZE; i++) {
		if(Math.random() < MUTATION_PROBABILITY) {
			if(Math.random() > 0.5) {
				population[i] = pushMutate(population[i]);
			} else {
				population[i] = doMutate(population[i]);
			}
			i--;
		}
	}
}

function doMutate(seq) {
	mutationTimes++;
  // m and n refers to the actual index in the array
  // m range from 0 to length-2, n range from 2...length-m
  do {
  	m = randomNumber(seq.length - 2);
  	n = randomNumber(seq.length);
  } while (m>=n)

  for(var i=0, j=(n-m+1)>>1; i<j; i++) {
  	seq.swap(m+i, n-i);
  }
  return seq;
}
function pushMutate(seq) {
	mutationTimes++;
	var m,n;
	do {
		m = randomNumber(seq.length>>1);
		n = randomNumber(seq.length);
	} while (m>=n)

	var s1 = seq.slice(0,m);
	var s2 = seq.slice(m,n)
	var s3 = seq.slice(n,seq.length);
	return s2.concat(s1).concat(s3).clone();
}
function setBestandWorstValue() {
	for(var i=0; i<population.length; i++) {
		values[i] = evaluate(population[i]);
	}
	currentBest = getCurrentBest();
	currentWorst = getCurrentWorst();
	if(bestValue === undefined || bestValue > currentBest.bestValue) {
		best = population[currentBest.bestPosition].clone();
		bestValue = currentBest.bestValue;
		arrayBestValue.push(bestValue);
	}
	if(worstValue === undefined || worstValue < currentWorst.worstValue){
		worst = population[currentWorst.worstPosition].clone();
		worstValue = currentWorst.worstValue;
	}
}

function stopCriteria(){

	if(currentGeneration>=1000){
		running = false;
	}
	if(arrayGen.length > arrayBestValue.length){
		arrayGen.pop();
		poped = poped+1;
		if(poped === 100){
			running = false;
		}
	}
	else poped = 0;
  //console.log(arrayBestValue);
  //console.log(arrayGen);
}
function getCurrentBest() {
	var bestP = 0;
	var candidaty = new Array();
	currentBestValue = (values[0]);
	for(var i=1; i<population.length; i++) {
		if((values[i]) < currentBestValue) {
			currentBestValue = values[i];
			bestP = i;
		}
	}
	bestparentx = Math.min.apply(null, values);
	for(var i=1; i<population.length; i++) {
		if (bestparentx<values[i]) {
			candidaty.push(values[i]);
		}
	}
	bestparenty = Math.min.apply(null, candidaty);
	return {
		bestPosition : bestP
		, bestValue    : currentBestValue
	}
}

function getCurrentWorst(){
	var worstP = 0;
	currentWorstValue = (values[0]);
	for(var i=1; i<population.length; i++) {
		if((values[i]) > currentWorstValue) {
			worstP = i;
		}
		currentWorstValue = bestValue;
	}
	return {
		worstPosition : worstP 
		,worstValue : currentWorstValue}
	}

	function setRoulette() {
  //calculate all the fitness
  for(var i=0; i<values.length; i++) { fitnessValues[i] = 1.0/values[i]; }
  //set the roulette
var sum = 0;
for(var i=0; i<fitnessValues.length; i++) { sum += fitnessValues[i]; }
	for(var i=0; i<roulette.length; i++) { roulette[i] = fitnessValues[i]/sum; }
		for(var i=1; i<roulette.length; i++) { roulette[i] += roulette[i-1]; }
	}
function wheelOut(rand) {
	var i;
	for(i=0; i<roulette.length; i++) {
		if(rand <= roulette[i] ) {
			return i;
		}
	}
}
function randomIndivial(n) {
	var a = [];
	for(var i=0; i<n; i++) {
		a.push(i);
	}
	return a.shuffle();
}
function evaluate(indivial) {
	var sum = dis[indivial[0]][indivial[indivial.length - 1]];
	for(var i=1; i<indivial.length; i++) {
		sum += dis[indivial[i]][indivial[i-1]];
	}
	return sum;
}
function countDistances() {
	//blackCounter();
	var length = points.length;
	dis = new Array(length);
	for(var i=0; i<length; i++) {
		dis[i] = new Array(length);
		for(var j=0; j<length; j++) {
			dis[i][j] = ~~distance(points[i], points[j]);
		}
	}
}
		function blackCounter() {
			var imageData = mymapctx.getImageData(0,0,WIDTH,HEIGHT);
			var data = imageData.data;
			var coordinates = [];
			for (var x = 0; x < mymapWIDTH; x++) {
				coordinates[x] = [];
				for (var y = 0; y < mymapHEIGHT; y++) {
					coordinates[x][y] = x+y;
				}
			}
			console.log(coordinates);
			for (var i = 0; i < data.length; i += 4) {
				if((data[i]+ data[i + 1] + data[i + 2] < 180)){
					data[i + 3] = 0;
				}
			}
			mymapctx.putImageData(imageData, 0, 0);
		};