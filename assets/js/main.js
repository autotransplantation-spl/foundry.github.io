//***********************************************
// Theme Name:  Discioar - Agency Html Template
// Theme URL: http://demo.towhidul.com/agency/
// Author: Themexbest
// Author URI: https://themeforest.net/user/themexbest/portfolio
// Creation Date:02/08/2017
// Description: A default stylesheet for Discioar - Agency HTML Template
// Version: 1.0
// Primary use: Discioar, agency, clean, contact form, creative, css3, fullscreen, gallery, html5, minimal, modern, parallax, photography, portfolio, responsive
// Support: rumon078102@gmail.com;
//***********************************************

(function ($) {
	"use strict";

	jQuery(document).ready(function ($) {
        
        /* 
		-----------------------
		PrettyPhoto
		-----------------------
		*/

		$("a[rel^='prettyPhoto']").prettyPhoto();
	 
		/* 
		-----------------------
		Soooth Scroll
		-----------------------
		*/

		 $('a[href*=#]:not([href=#])').on('click', function () {
          if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') || location.hostname == this.hostname) {
              var target = $(this.hash);
              target = target.length ? target : $('[name=' + this.hash.slice(1) + ']');
              if ($(window).width() < 768) {
                  if (target.length) {
                      $('html,body').animate({
                          scrollTop: target.offset().top - $('.navbar-header').outerHeight(true) + 1
                      }, 1000);
                      return false;
                  }
              } else {
                  if (target.length) {
                      $('html,body').animate({
                          scrollTop: target.offset().top - $('.navbar').outerHeight(true) + 1
                      }, 1000);
                      return false;
                  }
              }

          }
      });
		
		/* 
		-----------------------
		Counter UP
		-----------------------
		*/

		$('.counter').counterUp({
			delay: 10,
			time: 1000
		});

		
		
		/* 
		-----------------------
		Scroll Up
		-----------------------
		*/

		var offset = 220;
            var duration = 500;
            jQuery(window).scroll(function() {
                if (jQuery(this).scrollTop() > offset) {
                    jQuery('.top-arrow').fadeIn(duration);
                } else {
                    jQuery('.top-arrow').fadeOut(duration);
                }
            });

            jQuery('.top-arrow').on('click', function(event) {
                event.preventDefault();
                jQuery('html, body').animate({scrollTop: 0}, duration);
                return false;
            })
		
		/* 
		-----------------------
		Parallax
		-----------------------
		*/
		
		var parallaxHome = $(".banner-area.parallax"),
            parallaxFacts = $(".counter-area.parallax"),
            parallaxTest = $(".overlay-area.parallax");
            
        if (/Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent)) {
            parallaxHome.css({
                "background-attachment": "scroll"
            });
            parallaxFacts.css({
                "background-attachment": "scroll"
            });
            parallaxTest.css({
                "background-attachment": "scroll"
            });
        } else {
            parallaxHome.parallax("50%", 0.3);
            parallaxFacts.parallax("50%", 0.3);
            parallaxTest.parallax("50%", 0.2);
        }
        
        /* 
		-----------------------
		Our Clients Carousel
		-----------------------
		*/

		$('.client-wrap').owlCarousel({
			loop: true,
			margin: 10,
			autoplay: true,
			autoplayTimeout: 3000,
			smartSpeed: 2600,
			responsiveClass: true,
			responsive: {
				0: {
					items: 1,
					nav: false,
				},
				600: {
					items: 3,
					nav: false,
				},
				1000: {
					items: 4,
					nav: false,
					loop: true,
				}
			}
		});
        
        
        /* 
		-----------------------
		Accordion Box
		-----------------------
		*/
		
		if($('.accordion-box').length){
			$(".accordion-box").on('click', '.accord-btn', function() {

				if($(this).hasClass('active')!==true){
				$('.accordion .accord-btn').removeClass('active');

				}

				if ($(this).next('.accord-content').is(':visible')){
					$(this).removeClass('active');
					$(this).next('.accord-content').slideUp(300);
				}else{
					$(this).addClass('active');
					$('.accordion .accord-content').slideUp(300);
					$(this).next('.accord-content').slideDown(300);	
				}
			});	
		}
        
        
        
        
        /* 
		-----------------------
		Skill Animation
		-----------------------
		*/
		
		jQuery('.skillbar').each(function() {
			jQuery(this).appear(function() {
				jQuery(this).find('.count-bar').animate({
					width:jQuery(this).attr('data-percent')
				},3000);
				var percent = jQuery(this).attr('data-percent');
				jQuery(this).find('.count').html('<span>' + percent + '</span>');
			});
		});
        
         
        

        
        /* 
		-----------------------
		Single Testimonial Carousel
		-----------------------
		*/

		$('.single-testimonial-carousel').owlCarousel({
			loop: true,
			margin: 10,
			autoplay: true,
			autoplayTimeout: 5000,
			smartSpeed: 2600,
			responsiveClass: true,
			responsive: {
				0: {
					items: 1,
					nav: false,
				},
				600: {
					items: 1,
					nav: false,
				},
				1000: {
					items: 1,
					nav: false,
					loop: true,
				}
			}
		});
		
  

	}); // Ready
    
        

	/* 
	-----------------------
	Preloader
	-----------------------
	*/
	
	$(window).load(function () {
		$('#status').fadeOut();
		$('#preloader').delay(350).fadeOut('slow');
		$('body').delay(350).css({
			'overflow': 'visible'
		});
	});



}(jQuery));