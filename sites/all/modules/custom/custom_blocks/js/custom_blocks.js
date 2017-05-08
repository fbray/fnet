$(document).ready(function(){
	var formData = $('#blog-subscription-form').serialize();
	$("#blog-signup").click(function(){
		$.ajax({
			url: 'http://info.flukenetworks.com/index.php/leadCapture/save',
			type: "POST",
			data: formData,
			dataType: "json",
			success: function(data){
				alert("Successfull"+data);
			},
		});
	return false;
	});
});
