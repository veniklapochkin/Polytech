 'use strict';
 
 /* Controllers */

var InternetGis = angular.module('InternetGis', []);

InternetGis.controller('MainCtrl', function ($scope) {

  /* Fields */
  var map;
  var autocomplete;
  var geocoder;
  var directionsRenderer;
  var directionsService;
  var homeMark;
  var devCenter;
  var startPointLocation;
  var newCity;
  /* Properties */
  $scope.cities = [];

  /* Constructor */
  angular.element(document).ready(function(){
    initialize();
    //putTestPoints();
    setMapWidth();
    $(window).on('resize orientationChanged', setMapWidth); 
  });

  /* Methods */
  function initialize() {
    google.maps.visualRefresh = true;
    var mapOptions = {
        center: new google.maps.LatLng(59.939095, 30.100868),
        zoom: 11,
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };
      var renderOptions = {
              suppressBicyclingLayer: true,
              suppressInfoWindows: true,
              suppressMarkers: true
            };
    map = new google.maps.Map(document.getElementById("map_canvas"),
        mapOptions); 
    createHome();
    var input = document.getElementById('city-search');
    var options = {};
    autocomplete = new google.maps.places.Autocomplete(input, options);
    geocoder = new google.maps.Geocoder();
    directionsService = new google.maps.DirectionsService();
    directionsRenderer = new google.maps.DirectionsRenderer();
                //directionsRenderer will draw the directions on current map
            directionsRenderer.setMap(map);
            //directionsRenderer will list the textual description of the directions 
           //on directionsDiv HTML element
           directionsRenderer.setPanel(document.getElementById('DirectionsListDiv')); 
    google.maps.event.addListener(autocomplete, 'place_changed', $scope.addCity);
  };

  $scope.addCity = function() {
    var place = autocomplete.getPlace();
    if (!place.geometry) {return;}

    directionsRenderer.setMap(null);
    $scope.showMarkers();

    var name = place.formatted_address;
    var location = place.geometry.location;
    var marker = new google.maps.Marker({
        map: map,
        position: location,
        draggable: true
    });

    var grepFunc = function(el, i) {
      if (el.name == name) {return true};
      return false;
    };

    if ($.grep($scope.cities, grepFunc).length == 0) {
      map.setCenter(location);
      newCity = {'name': name, "location": location, "marker": marker};
      $scope.cities.push(newCity);          
    } else {
      $("#search-box").notify(
        "This point has already been added", 
        { position:"bottom left" }
      );
    }

    place = null;
    $scope.newCityName = null;
    $scope.$apply();  
  };

  $scope.removeCity = function(index){
    directionsRenderer.setMap(null);
    $scope.showMarkers();
    $scope.cities[index].marker.setMap(null);
    $scope.cities.splice(index, 1);
  };

  $scope.showCity = function(index){
    map.setCenter($scope.cities[index].marker.position);
  };

  $scope.startPointChanged = function(){
    if ($scope.startPoint == $scope.endPoint) {
      $scope.endPoint = null;
    };
  };

  $scope.calculatePath = function(){
    if (checkConstraints()){

      startPointLocation = $.grep($scope.cities, function(el){ return el.name == $scope.startPoint; })[0].location;
      var endPointLocation;
      if ($scope.backToStart) {
        endPointLocation = $.grep($scope.cities, function(el){ return el.name == $scope.startPoint; })[0].location;
      } else {
        endPointLocation = $.grep($scope.cities, function(el){ return el.name == $scope.endPoint; })[0].location;
      };

      

      var waypointsGrep = function(el, i) {
        if (el.name == $scope.startPoint){ return false; }
        if (!$scope.backToStart && el.name == $scope.endPoint) { return false; }
        return true;
      }

      var intermediateCities = $.grep($scope.cities, waypointsGrep);
      var waypts = [];
      $.each(intermediateCities, function(i, el){
        waypts.push({
          location: el.location
        });
      });

      var request = {
        origin: startPointLocation,
        destination: endPointLocation,
        waypoints: waypts,
        optimizeWaypoints: true,
        travelMode: google.maps.TravelMode.DRIVING
      };

      showLoadingAnimation();
      directionsService.route(request, function(response, status) {
        stopLoadingAnimation();
        if (status == google.maps.DirectionsStatus.OK) {
          $scope.hideMarkers();
          var totalDistance = 0;
		  var totalDuration = 0;
		var legs = response.routes[0].legs;
		for(var i=0; i<legs.length; ++i) {
		    totalDistance += legs[i].distance.value;
		    totalDuration += legs[i].duration.value;
		}
		totalDistance = (totalDistance / 1000).toFixed(1);
		totalDuration = (totalDuration / 60).toFixed(1);
		$('#distance').text("Trip Distance: "+totalDistance+" km ");
		$('#duration').text("Trip Duration:" +totalDuration+" min ");
          directionsRenderer.setMap(map);
          directionsRenderer.setDirections(response);
        } else {
          var error;
          if (status == google.maps.DirectionsStatus.ZERO_RESULTS)
            { error = "Failed to get directions"; }
          else { error = status; }
          $("#b-calculate").notify(
            "Error: "+ error,
            { position: "right top" }
          );
        }

      });

    }
  };

  function checkConstraints(){
    var result = true;
    if ($scope.cities.length < 2) {
      $("#cities-list").notify(
        "Add two or more address on the list",
        { position: "right top" }
        );
      result = false;      
    };

    if (!$scope.startPoint) {
      $("#start-point-select").notify(
        "Select the start point of the route",
        { position: "right top" }
        );
      result = false; 
    }

    if (!$scope.backToStart && !$scope.endPoint) {
      $("#end-point-select").notify(
        "Select the end point of the route",
        { position: "right top" }
        );
      result = false; 
    }


    return result;
  };

  function setMapWidth() {
    var cpWidth = $("#control_panel").width();
    var mapWidth = $("body").innerWidth() - cpWidth - 40;
    $("#map_canvas").width(mapWidth);
  };

  function createHome() {
          if (navigator.geolocation) {

            navigator.geolocation.getCurrentPosition(function (position) {

                      //Creating LatLng object with latitude and //longitude.
                      devCenter = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
                      homeMark = new google.maps.Marker({
                        position: devCenter,
                        map: map,
                        draggable: true,
                          
                      });
                      
                      $scope.backToHome();
                  });

          }
         }
  $scope.hideMarkers = function() {
    $.each($scope.cities, function(i, el){
      el.marker.setMap(null);
    });
  };

  $scope.showMarkers = function() {
    $.each($scope.cities, function(i, el){
      el.marker.setMap(map);
    });
  };
  $scope.backToHome = function() {
        map.panTo(homeMark.getPosition());
        map.setZoom(11);
       } 
  function showLoadingAnimation() {    
    $("#b-calculate").attr("disabled" ,"disabled");
    $("#b-calculate").text("Plot a route...");
  }

  function stopLoadingAnimation() {    
    $("#b-calculate").removeAttr("disabled");
    $("#b-calculate").text("Find the best route");
  }

});