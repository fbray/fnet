


$(document).ready(function () {

	$(".download-options").mouseover( function() {
		$( '.active-list').removeClass('active-list');
		$( this ).closest(".box-thumbnail-entry").find(".image-size-list").addClass('active-list');
	})

})

