$(document).ready(function(){
	var kbwidget = $(".ui-widget-content a.active");
	if($(".ui-widget-content a").hasClass("active")){
		var headerindex = kbwidget.closest("div.ui-accordion-content").prev("h3.ui-accordion-header").index();
		switch(headerindex){
			case 0:
				headerindex = headerindex;
				break;
			case 2:
				headerindex = headerindex -1;
				break;
			case 4:
				headerindex = headerindex -2;
				break;
		}
    $(".ui-accordion").accordion('option', 'active' , headerindex); 
		kbwidget.closest("span.field-content").closest("div.views-field").css("background-color","#F5F5F5");
	}
});