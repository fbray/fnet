var mapLocation = new google.maps.LatLng(-23.6324589, -46.721486); //change coordinates here
var marker;
var map;

function initialize() {
    var mapOptions = {
        zoom: 17, // Change zoom here
        center: mapLocation,
        scrollwheel: false,
        styles: [
            {"featureType":"administrative","elementType":"labels.text.fill","stylers":[{"color":"#333333"}]},
            {"featureType":"landscape","elementType":"all","stylers":[{"color":"#f2f2f2"}]},
            {"featureType":"poi","elementType":"all","stylers":[{"visibility":"off"}]},
            {"featureType":"poi","elementType":"labels.text","stylers":[{"visibility":"off"}]},
            {"featureType":"road","elementType":"all","stylers":[{"saturation":-100},{"lightness":45}]},
            {"featureType":"road.highway","elementType":"all","stylers":[{"visibility":"simplified"}]},
            {"featureType":"road.arterial","elementType":"labels.icon","stylers":[{"visibility":"off"}]},
            {"featureType":"transit","elementType":"all","stylers":[{"visibility":"off"}]},
            {"featureType":"water","elementType":"all","stylers":[{"color":"#dbdbdb"},{"visibility":"on"}]}]
    };
    
    map = new google.maps.Map(document.getElementById('map'),
    mapOptions);
    
    
    //change address details here
    var contentString = '<div class="map-info">' 
    + '<div class="map-title">' 
    + '<h3><img alt="" width="140" src="img/brand.png"></h3></div>' 
    + '<p class="map-address"><div class="map-address-row"><i class="fa fa-map-marker"></i><span class="text"><strong>Fluke Networks</strong><br>Av. Major Sylvio de Magalhães Padilha, 5200 Bloco B – Conj. 42</span></div><div class="map-address-row"><i class="fa fa-phone"></i><span class="text">+55 11 4058-0200</span></div><div class="map-address-row"><span class="map-email"><i class="fa fa-envelope"></i><span class="text">marketing@flukenetworks.com.br</span></span></p>' 
    + '<p class="gmap-open"><a href="https://www.google.com.br/maps?q=Av.+Major+Sylvio+de+Magalh%C3%A3es+Padilha,&um=1&ie=UTF-8&sa=X&ved=0ahUKEwjJtpzCjc7OAhUKIpAKHTagBEsQ_AUICCgB" target="_blank">Open on Google Maps</a></p></div>';
    
    
    var infowindow = new google.maps.InfoWindow({
        content: contentString,
    });
    

    marker = new google.maps.Marker({
        map: map,
        draggable: true,
        title: 'Vanessa', //change title here
        animation: google.maps.Animation.DROP,
        position: mapLocation
    });

    google.maps.event.addListener(marker, 'click', function() {
        infowindow.open(map, marker);
    });


    infowindow.open(map, marker);

}

if ($('#map').length) {
    google.maps.event.addDomListener(window, 'load', initialize);
}

