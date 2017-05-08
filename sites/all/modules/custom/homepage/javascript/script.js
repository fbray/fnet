(function($) {
    $(function() {
        $('.jcarousel')
            // Bind _before_ carousel initialization
            .on('jcarousel:targetin', 'li', function() {
                $(this).addClass('target');
            })
            .on('jcarousel:targetout', 'li', function() {
                $(this).removeClass('target');
            })
            .jcarousel({
                wrap:'circular'
            })
            .jcarouselAutoscroll({
                interval: 6000,
                target: '+=1',
                autostart: true
            });

        $('.jcarousel-control-prev')
            .on('jcarouselcontrol:active', function() {
                $(this).removeClass('inactive');
            })
            .on('jcarouselcontrol:inactive', function() {
                $(this).addClass('inactive');
            })
            .jcarouselControl({
                target: '-=1'
            });

        $('.jcarousel-control-next')
            .on('jcarouselcontrol:active', function() {
                $(this).removeClass('inactive');
            })
            .on('jcarouselcontrol:inactive', function() {
                $(this).addClass('inactive');
            })
            .jcarouselControl({
                target: '+=1'
            });

        $('.jcarousel-pagination')
            .on('jcarouselpagination:active', 'a', function() {
                $(this).addClass('active');
            })
            .on('jcarouselpagination:inactive', 'a', function() {
                $(this).removeClass('active');
            })
            .jcarouselPagination({'perPage': 1});
    });
})(jQuery);