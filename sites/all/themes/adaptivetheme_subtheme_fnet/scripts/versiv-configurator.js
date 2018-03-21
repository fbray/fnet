var con_cat8 = true;
! function() {
    for (var n = 0, e = ["ms", "moz", "webkit", "o"], t = 0; t < e.length && !window.requestAnimationFrame; ++t) window.requestAnimationFrame = window[e[t] + "RequestAnimationFrame"], window.cancelAnimationFrame = window[e[t] + "CancelAnimationFrame"] || window[e[t] + "CancelRequestAnimationFrame"];
    window.requestAnimationFrame || (window.requestAnimationFrame = function(e, t) {
        var o = (new Date).getTime(),
            i = Math.max(0, 16 - (o - n)),
            a = window.setTimeout(function() {
                e(o + i)
            }, i);
        return n = o + i, a
    }), window.cancelAnimationFrame || (window.cancelAnimationFrame = function(n) {
        clearTimeout(n)
    })
}(),
function() {
    window.applicationCache && window.applicationCache.addEventListener("updateready", function() {
        window.applicationCache.swapCache(), window.location.reload()
    }, !1)
}(), String.prototype.trim || (String.prototype.trim = function() {
    return this.replace(/^\s+|\s+$/g, "")
}), _.defer(function($) {
    if (window.Configurator) {
        var n = function(n) {
                var e = $("html").hasClass("ie8");
                _.each(n, function(n, t) {
                    if (!n.fuzzy && !n.add) {
                        var o = $("<li><h2>" + n.name.replace(/\n/g, "<br />") + '</h2><span class="special"></span></li>').addClass(n.id.toLowerCase()).appendTo("#family");
                        $("<img />").prependTo(o).on("load", function(n) {
                            $(this).addClass("loaded")
                        }).attr("src", "http://www.flukenetworks.com/sites/default/files" + "/" + n.id.toLowerCase() + ".png")
                    }
                })
            },
            e = function(n) {
                _.each(n, function(n, e) {
                    var t = $("<li><h2>" + n.name + "</h2></li>"),
                        o = $("<ul></ul>").appendTo(t),
                        i = n.single ? "radio" : "checkbox";
                    _.each(n.options, function(t, a) {
                        var r = $("<li></li>"),
                            s = $("<label><span>" + t.name + "</span></label>").appendTo(r),
                            d = $('<input type="' + i + '" />');
                        n.single && d.attr("name", "category_" + e), t.requires ? d.addClass("requires").val(t.requires.join(",")) : t.provides ? d.addClass("provides").val(t.provides.join(",")) : t.adds ? d.addClass("adds").val(t.adds.join(",")) : d.val(""), d.prependTo(s), r.appendTo(o)
                    }), t.appendTo("#criteria")
                })
            };
        jQuery(function($) {
            n(Configurator.modules), e(Configurator.criteria), $("#configurator").addClass("loaded")
        })
    }
}, jQuery), _.defer(function($, n) {
    n.on("change", "#criteria input", function(n) {
        var e = [],
            t = [],
            o = [],
            i = function(n, e) {
                var t = $(e).val();
                if (($('ul#criteria li:first ul > li > label > input[type="checkbox"]').is(':checked')) || ($('ul#criteria li:first ul > li > label > input[type="checkbox"]').is(':checked') && $('ul#criteria li:nth-child(6) ul > li > label > input[type="checkbox"]').is(':checked'))) {
                
                    $('input.requires:not(:checked)').attr('disabled', 'disabled');
                    $('input.provides:not(:checked)').attr('disabled', 'disabled');
                }/* else if($('ul#criteria li:nth-child(2) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(2) ul > li > label > input[type="checkbox"]').is(':checked') &&  $('ul#criteria li:nth-child(6) ul > li > label > input[type="checkbox"]').is(':checked')){
                   
                      $('ul#criteria li:nth-child(7) ul > li:nth-child(2) > label > input[type="checkbox"]').attr('disabled', 'disabled');

                }*/
                else if ($('ul#criteria li:nth-child(2) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(3) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(4) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(5) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(7) ul > li > label > input[type="checkbox"]').is(':checked')

                ) {
               
                    $('ul#criteria li:first ul > li > label > input[type="checkbox"]').attr('disabled', 'disabled');


                } 
                else {
               
                    $('input.requires').removeAttr('disabled');
                    $('input.provides').removeAttr('disabled');
                }
                if (t) return _.union(n, t.split(","))
            };
        m = function(n, e) {
            var t = $(e).val();
            if (t.split(",") == "DV,FI,dsx8,CU,OLTS1,OLTS2,OTDR1,OTDR2,MISC1,MISC2,MISC3,MISC4,MISC5") {
           
                $('input.requires:not(:checked)').attr('disabled', 'disabled');
                $('input.provides:not(:checked)').attr('disabled', 'disabled');
            } else {
            
                $('input.requires').removeAttr('disabled');
                $('input.provides').removeAttr('disabled');
            }
            if (t) return _.union(n, t.split(","))
        };
        $inputs1 = $("#criteria input:not(:checked)").each(function() {
            m = i(e, this)
        });
        $inputs = $("#criteria input:checked").each(function() {
            e = i(e, this)
        }).filter(".adds").each(function() {
            t = i(t, this)
        }).end().filter(".provides").each(function() {
            o = i(o, this)
        }), $modules = $("#family").each(function() {
            this.className = _.map(e, function(n) {
                return n.toLowerCase()
            }).join(" ")
        }).children().removeClass("required owns"), e.length > 0 ? ($modules.filter("." + _.map(e, function(n) {
            return n.toLowerCase()
        }).join(",.")).addClass("required"), $("#configurator,#configure").addClass("scored")) : $("#configurator,#configure").removeClass("scored"), o.length > 0 && $modules.filter("." + _.map(o, function(n) {
            return n.toLowerCase()
        }).join(",.")).addClass("owns"), _.difference(_.difference(e, t), o).length > 0 ? $("#configurator").addClass("needs") : $("#configurator").removeClass("needs"), $("#configurator,#configure").addClass("redraw").removeClass("redraw")
    }).on("change", "#addon input", function(n) {
        var e = _.union(_.map($("#addon input:checked"), function(n) {
                return $(n).val()
            }), _.pluck(_.filter(Configurator.connectors.filters, function(n) {
                return n.value ? _.intersection(n.supports, Configurator.bom.supports).length > 0 : !1
            }), "value")),
            t = $("summary-addon").empty(),
            o = [],
            i = [];
        _.each(Configurator.bom.bundles, function(n) {
            n.connectors && _.each(n.connectors, function(n) {
                i.push(n)
            })
        }), _.each(Configurator.connectors.items, function(n) {
            if (!_.contains(i, n.id)) {
                if (!n.type || n.type.length <= 0) return;
                if (!n.supports || n.supports.length <= 0) return;
                if (_.intersection(n.type, e).length < n.type.length) return
            }
            _.each(n.supports, function(e) {
                if (_.contains(Configurator.bom.supports, e.id)) {
                    var t = !1;
                    _.each(o, function(o) {
                        o.id == n.id && (t = !0, o.quantity = Math.max(o.quantity, e.quantity))
                    }), t || o.push({
                        id: n.id,
                        name: n.name,
                        quantity: e.quantity
                    })
                }
            })
        }), $("#summary-addon").empty().append(_.map(o, function(n) {
            return $("<tr><td>" + n.quantity + "</td></tr>").append('<th scope="row"><strong>' + n.id + "</strong></th>").append("<td><p>" + n.name + "</p></td>")
        }))
    }).on("click", "button#print", function(n) {
       Munchkin.munchkinFunction('clickLink', {href: '/VersivConfigPrintButton'}),
      n.preventDefault(), window.print()
      }).on("click", "button#send", function(n) {
        n.preventDefault(), $("#summary-send").removeClass("sent"), $.fancybox.open({
            href: "#summary-send",
            width: 600,
            padding: 0,
            closeBtn: !1,
            modal: !0
        })
    }).on("submit", "form#summary-send", function(n) {
        var e = $(this),
            t = [
                ["table", {
                    color: "#252525",
                    "font-size": "12px",
                    "border-collapse": "separate",
                    "border-spacing": "0"
                }],
                ["table caption", {
                    "text-align": "left",
                    color: "#000",
                    "font-size": "25px",
                    padding: "0 0 15px 0"
                }],
                ["table th, table td", {
                    padding: "10px 0",
                    "text-align": "left",
                    "vertical-align": "middle",
                    "font-weight": "normal",
                    "font-family": "arial, sans-serif"
                }],
                ["table td ~ td", {
                    padding: "10px 20px 10px 0"
                }],
                ["table thead th, table th[colspan]", {
                    background: "#fff",
                    color: "#252525",
                    "font-weight": "bold"
                }],
                ["table thead th:first-child", {
                    width: "4em"
                }],
                ["table thead th", {
                    "border-bottom": "solid 1px #e3e4e6"
                }],
                ["table tbody th[colspan]", {
                    "border-top": "solid 1px #e3e4e6",
                    "border-bottom": "solid 1px #e3e4e6"
                }],
                ["table tbody h1,table tbody strong", {
                    "font-weight": "bold"
                }],
                ["table td:first-child", {
                    "text-align": "center",
                    "vertical-align": "middle"
                }]
            ],
            o = $("<div />").append($("#summary table").clone().attr("width", "100%")).each(function(n) {
                var e = $(this);
                _.each(t, function(n) {
                    e.find(n[0]).css(n[1])
                })
            }).find("ul").remove().end().html();
        e.find("input[name='emailbody']").val(o), e.addClass("sending"), $('<iframe src="about:blank" name="fnetemail" style="position:absolute;height:0;width:0;border:0;overflow:hidden;visibility:hidden;" marginwidth="0" marginheight="0" frameborder="0" scrolling="no" allowtransparency="true"></iframe>').appendTo("body").on("load", function(n) {
            e.removeClass("sending").addClass("sent").trigger("reset"), $(this).remove()
        }), e.attr("target", "fnetemail")
    }).on("click", "form#summary-send button[type=reset]", function(n) {
        n.preventDefault(), $(this).closest("form").trigger("reset")
    }).on("reset", "form#summary-send", function(n) {
        var e = $(this);
        e.hasClass("sending") ? n.preventDefault() : e.hasClass("sent") ? _.delay(function() {
            $.fancybox.close()
        }, 3e3) : $.fancybox.close()
    })
}, jQuery, jQuery(document)), _.defer(function($, n) {
    var e = {},
        t = {};
    _.each(Configurator.modules, function(n, o) {
        e[n.id] = n, t[n.id] = n.supports && n.supports.length > 0 ? _.union(n.supports) : [n.id]
    }), _.each(Configurator.bundles, function(n) {
        e[n.id] = n
    }), _.each(Configurator.accessories, function(n) {
        e[n.id] = n
    }), _.each(Configurator.support, function(n) {
        e[n.id] = n
    });
    var o = function(n) {
        var e = function(o, i, a) {
            _.each(Configurator.bundles, function(r) {
                if (!(_.reduce(i.bundles, function(n, e) {
                        return n + e.modules.length
                    }, 0) + r.modules.length > n.length || _.contains(_.pluck(i.bundles, "id"), r.id))) {
                    for (var s = 0; s < r.modules.length; s++)
                        if (_.intersection(t[r.modules[s]], n).length <= 0) return;
                    if (supports = [], _.each(r.modules, function(n) {
                            supports = _.union(supports, t[n])
                        }), !(_.intersection(i.supports, supports).length > 0)) {
                        for (var d = {
                                msrp: i.msrp + r.msrp + _.reduce(_.pluck(supports, "price"), function(n, e) {
                                    return n + (e || 0)
                                }, 0),
                                bundles: i.bundles.concat([r]),
                                supports: i.supports.concat(supports)
                            }, s = 0; s < n.length; s++)
                            if (!_.contains(d.supports, n[s])) return void(a && e(o, d, !0));
                        o.push(d)
                    }
                }
            })
        };
        return jQuery.Deferred(function(t) {
            return 0 == n.length ? void t.reject() : void requestAnimationFrame(function() {
                var n = [];
                if (e(n, {
                        msrp: 0,
                        bundles: [],
                        supports: []
                    }, !0), n.length > 0) {
                    n = _.sortBy(n, "msrp");
                    var o = n[0];
                    if (o.bundles.length > 1) {
                        var i = _.filter(n, function(n) {
                            return 1 == n.bundles.length
                        });
                        i.length > 0 && i[0].msrp - 2e3 <= o.msrp && (o = i[0])
                    }
                    t.resolve(o)
                } else t.reject()
            })
        }).promise()
    };
    n.on("submit", "#configure", function(n) { 
        n.preventDefault();
        var t = [], temp_t = [], wifi=1,
            i = [];
        if ($(this).find("input:checked").not(".provides").each(function() {
                var n = $(this).val();
                n && (t = _.union(t, n.split(",")))
            }).end().filter(".adds").each(function() {
                var n = $(this).val();
                n && (i = _.union(i, n.split(",")), t = _.difference(t, n.split(","))); 
            }).end().filter(".provides").each(function() {
                var n = $(this).val();
                n && (t = _.difference(t, n.split(",")))
            }), !(t.length <= 0)) { 
            var a = $("#summary-required").empty(),
                r = $("#summary-suggested").find("tr:first-child ~ tr").remove().end();
								var regCountryCookie = getCookie("regCountry") ? getCookie("regCountry") : "";
								// var wifi_countries = ["AU","AT","BE","BR","BG","CA","HR","CY","CZ","DK","EE","FI","FR","DE","GR","HU","IS","IN","IE","IT","LV","LI","LT","LU","MY","MT","MX","NL","NO","PL","PT","RO","SG","SK","RI","ES","SE","CH","TH","UK","US","VN"];
								var wifi_countries = ["AR","CH","RU"];
								if(jQuery.inArray(regCountryCookie,wifi_countries) !== -1){
									wifi=0;
								}else{
									if(t.length==1){
											if(t[0] == "DSX8CU" || t[0] == "OLTS1"|| t[0] == "OLTS2"|| t[0] == "OTDR1"|| t[0] == "OTDR2"|| t[0] == "FI")
													wifi=0;
									}else if(t.length == 2){
											if((t[0] == "VRM" && t[1] == "DSX8CU") || 
													(t[0] == "DSX8CU" && t[1] == "FI")|| 
													(t[0] == "DSX8CU" && t[1] == "OLTS1")|| 
													(t[0] == "DSX8CU" && t[1] == "OLTS2")|| 
													(t[0] == "DSX8CU" && t[1] == "OTDR1")|| 
													(t[0] == "DSX8CU" && t[1] == "OTDR2")||																		
													(t[0] == "VRM" && t[1] == "FI")|| 
													(t[0] == "VRM" && t[1] == "OLTS1")|| 
													(t[0] == "VRM" && t[1] == "OLTS2")|| 
													(t[0] == "VRM" && t[1] == "OTDR1")|| 
													(t[0] == "VRM" && t[1] == "OTDR2")|| 
													(t[0] == "OLTS1" && t[1] == "OLTS2")|| 
													(t[0] == "OTDR1" && t[1] == "OTDR2")|| 
													(t[0] == "OTDR1" && t[1] == "OLTS2")|| 
													(t[0] == "OTDR1" && t[1] == "OLTS1")|| 
													(t[0] == "OLTS1" && t[1] == "OTDR1")|| 
													(t[0] == "OLTS1" && t[1] == "OTDR2")|| 
													(t[0] == "OLTS2" && t[1] == "OTDR2")|| 
													(t[0] == "OLTS1" && t[1] == "FI")|| 
													(t[0] == "OLTS2" && t[1] == "FI")|| 
													(t[0] == "OTDR1" && t[1] == "FI")|| 
													(t[0] == "OTDR2" && t[1] == "FI"))
													wifi=0;
									}else if(t.length == 3){
											if((t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "FI") || 
													(t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS1") || 
													(t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS2") || 
													(t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OTDR1") || 
													(t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OTDR2") || 
													(t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OLTS2") || 
													(t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OTDR1") || 
													(t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OTDR2") || 
													(t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "FI") || 
													(t[0] == "VRM" && t[1] == "OLTS2" && t[2] == "OTDR1") || 
													(t[0] == "VRM" && t[1] == "OLTS2" && t[2] == "OTDR2") || 
													(t[0] == "VRM" && t[1] == "OLTS2" && t[2] == "FI") || 
													(t[0] == "VRM" && t[1] == "OTDR1" && t[2] == "FI") || 
													(t[0] == "VRM" && t[1] == "OTDR2" && t[2] == "FI") || 
													(t[0] == "VRM" && t[1] == "OTDR1" && t[2] == "OTDR2")|| 
													(t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OLTS2") || 
													(t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OTDR1") || 
													(t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OTDR2") || 
													(t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "FI") || 
													(t[0] == "DSX8CU" && t[1] == "OLTS2" && t[2] == "OTDR1") || 
													(t[0] == "DSX8CU" && t[1] == "OLTS2" && t[2] == "OTDR2") || 
													(t[0] == "DSX8CU" && t[1] == "OLTS2" && t[2] == "FI") || 
													(t[0] == "DSX8CU" && t[1] == "OTDR1" && t[2] == "FI") || 
													(t[0] == "DSX8CU" && t[1] == "OTDR2" && t[2] == "FI") || 
													(t[0] == "DSX8CU" && t[1] == "OTDR1" && t[2] == "OTDR2") ||
												 (t[0] == "OLTS1" && t[1] == "OTDR1" && t[2] == "OTDR2") || 
												 (t[0] == "OLTS1" && t[1] == "OTDR1" && t[2] == "FI") || 
												 (t[0] == "OLTS1" && t[1] == "OTDR2" && t[2] == "FI") || 
												 (t[0] == "OLTS2" && t[1] == "OTDR1" && t[2] == "OTDR2") || 
												 (t[0] == "OLTS2" && t[1] == "OTDR1" && t[2] == "FI") || 
												 (t[0]== "OLTS2" && t[1] == "OTDR2" && t[2] == "FI") || 
												 (t[0]== "OLTS1" && t[1] == "OLTS2" && t[2] == "OTDR1") || 
												 (t[0] == "OLTS1" && t[1] == "OLTS2" && t[2] == "OTDR2") || 
												 (t[0] == "OLTS1" && t[1] == "OLTS2" && t[2] == "FI") || 
												 (t[0] == "OTDR1" && t[1] == "OTDR2" && t[2] == "FI"))
													wifi=0;
									}else if(t.length == 4){
											if((t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS1" && t[3] == "OLTS2") || 
												 (t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OTDR1" && t[3] == "OTDR2") || 
												 (t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS1" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS2" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OTDR1" && t[3] == "OTDR2") || 
												 (t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OTDR1" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OTDR2" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "OLTS2" && t[2] == "OTDR1" && t[3] == "OTDR2") || 
												 (t[0] == "VRM" && t[1] == "OLTS2" && t[2] == "OTDR1" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "OLTS2" && t[2] == "OTDR2" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OLTS2" && t[3] == "OTDR1") || 
												 (t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OLTS2" && t[3] == "OTDR2") || 
												 (t[0] == "VRM" && t[1] == "OLTS1" && t[2] == "OLTS2" && t[3] == "FI") || 
												 (t[0] == "VRM" && t[1] == "OTDR1" && t[2] == "OTDR2" && t[3] == "FI")||																	 
												 (t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OTDR1" && t[3] == "OTDR2") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OTDR1" && t[3] == "FI") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OTDR2" && t[3] == "FI") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS2" && t[2] == "OTDR1" && t[3] == "OTDR2") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS2" && t[2] == "OTDR1" && t[3] == "FI") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS2" && t[2] == "OTDR2" && t[3] == "FI") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OLTS2" && t[3] == "OTDR1") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OLTS2" && t[3] == "OTDR2") || 
												 (t[0] == "DSX8CU" && t[1] == "OLTS1" && t[2] == "OLTS2" && t[3] == "FI") || 
												 (t[0] == "DSX8CU" && t[1] == "OTDR1" && t[2] == "OTDR2" && t[3] == "FI")||
												 (t[0]=="OLTS1" && t[1]=="OLTS2" && t[2]=="OTDR1" && t[3]=="OTDR2") || 
												 (t[0]=="OLTS1" && t[1]=="OLTS2" && t[2]=="OTDR1" && t[3]=="FI") || 
												 (t[0]=="OLTS1" && t[1]=="OLTS2" && t[2]=="OTDR2" && t[3]=="FI") || 
												 (t[0]=="OLTS2" && t[1]=="OTDR1" && t[2]=="OTDR2" && t[3]=="FI") || 
												 (t[0]=="OLTS1" && t[1]=="OTDR1" && t[2]=="OTDR2" && t[3]=="FI"))
													wifi=0;
									}else if(t.length == 5){
											if((t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS1" && t[3] == "OLTS2" && t[4]=="FI") ||
												 (t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS1" && t[3] == "OTDR1" && t[4]=="FI") ||
												 (t[0] == "VRM" && t[1] == "DSX8CU" && t[2] == "OLTS1" && t[3] == "OTDR2" && t[4]=="FI") ||
												 (t[0]=="VRM" && t[1]=="OLTS1" && t[2]=="OLTS2" && t[3]=="OTDR1" && t[4]=="OTDR2") ||
												 (t[0]=="DSX8CU" && t[1]=="OLTS1" && t[2]=="OLTS2" && t[3]=="OTDR1" && t[4]=="OTDR2") || 
												 (t[0]=="DSX8CU" && t[1]=="OLTS1" && t[2]=="OLTS2" && t[3]=="OTDR1" && t[4]=="FI") || 
												 (t[0]=="DSX8CU" && t[1]=="OLTS1" && t[2]=="OLTS2" && t[3]=="OTDR2" && t[4]=="FI") || 
												 (t[0]=="DSX8CU" && t[1]=="OLTS2" && t[2]=="OTDR1" && t[3]=="OTDR2" && t[4]=="FI") || 
												 (t[0]=="DSX8CU" && t[1]=="OLTS1" && t[2]=="OTDR1" && t[3]=="OTDR2" && t[4]=="FI") ||
												 (t[0]=="OLTS1" && t[1]=="OLTS2" && t[2]=="OTDR1" && t[3]=="OTDR2" && t[4]=="FI"))
													wifi=0;
									}else if(t.length == 6){
											if(t[0]=="DSX8CU" && t[1]=="OLTS1" && t[2]=="OLTS2" && t[3]=="OTDR1" && t[4]=="OTDR2" && t[5]=="FI")
													wifi=0;
									}
								}
								if(wifi == 1){
									 t.push('VERSIV-ADP-WIFI');
								} 
                if (con_cat8) {
                    Configurator.connectors.filters[0].options[0].preselect = true;
                }else {
                    t = JSON.parse(JSON.stringify(t).replace('DSX8CU', 'CU'));	
										if(t.length == 13 || (t.length == 6 && (t[0] == "VMF" && t[1] == "VRM" && t[2] == "CU" && t[3] == "OLTS2" && t[4]=="FI" && t[5]=="VERSIV-ADP-WIFI")) || (t.length == 9 && (t[0] == "VMF" && t[1] == "VRM" && t[2] == "CU" && t[3] == "OLTS1" && t[4]=="OLTS2"  && t[5] == "OTDR1" && t[6]=="OTDR2" && t[7]=="FI" && t[8]=="VERSIV-ADP-WIFI"))){
											t = _.reject(t, function(mod){ return (mod=="VERSIV-ADP-WIFI"?1:0) });
										}
                    Configurator.connectors.filters[0].options[0].preselect = false;
                }
            o(t).then(function(n) {
                Configurator.bom = n;
                var t = [],
                    o = [],
                    r = [];
                _.each(n.bundles, function(n) { 
                    var a = n,
                        s = [];
                    n.support && n.support.substitute && (s = _.intersection(i, _.keys(n.support.substitute))).length > 0 ? a = e[n.support.substitute[s[0]]] : n.support && n.support.add && (s = _.intersection(i, _.keys(n.support.add))).length > 0 ? _.each(n.support.add[s[0]], function(n) { 
                        var t = e[n];
                        t && o.push({
                            id: t.id,
                            name: t.name,
                            quantity: 1
                        })
                    }) : n.support && n.support.add && _.each(_.flatten(_.values(n.support.add)), function(n) { 
                        var t = e[n];
                        t && r.push({
                            id: t.id,
                            name: t.name,
                            quantity: 1
                        })
                    }), t.push(a)
                }), _.each(t, function(t) {
                    _.each(t.accessories, function(t) {
                        if (window.console && console.log(t.id), !_.contains(n.supports, t.id)) {
                            var o = !1,
                                i = e[t.id];
                            t.quantity && t.quantity > 0 && (_.each(r, function(n) {
                                n.id == t.id && (o = !0, n.quantity = Math.max(n.quantity, t.quantity))
                            }), o || r.push({
                                id: t.id,
                                name: i.name,
                                quantity: t.quantity
                            }))
                        }
                    })
                });
                var s = function() {
                    _.each(t, function(n) {                            
                        var t = $("<tr><td>1</td></tr>").appendTo(a),
                            o = $('<th scope="row"></th>').appendTo(t),
                            i = $("<td><p>" + n.name + "</p></td>").appendTo(t),
                            r = $('<ul class="images"></ul>').appendTo(o);
                            o.append("<strong>" + n.id + "</strong>");
                        
                        var s = $('<ul class="contents"></ul>').appendTo(i);
                        _.chain(n.modules).map(function(n) {
                            return e[n]
                        }).each(function(n, e) {
                            var t = $("<li>" + n.name + "</li>").addClass(n.id.toLowerCase()).appendTo(s),
                                o = $("<li></li>").addClass(n.id.toLowerCase()).appendTo(r);
                            $("<img />").appendTo(o).on("load", function(n) {
                                $(this).addClass("loaded")
                            }).attr("src", "http://www.flukenetworks.com/sites/default/files" + "/" + n.id.toLowerCase() + "-sm.png")
                        }) 
                        // }
                    }), $("#summary-required").append(_.map(o, function(n) {
                        return $("<tr><td>" + n.quantity + "</td></tr>").append('<th scope="row"><strong>' + n.id + "</strong></th>").append("<td><p>" + n.name + "</p></td>")
                    })), $("#summary-suggested").append(_.map(r, function(n) {
                        return $("<tr><td>" + n.quantity + "</td></tr>").append('<th scope="row"><strong>' + n.id + "</strong></th>").append("<td><p>" + n.name + "</p></td>")
                    }));
                    
                    var i = $("#addon > ul").empty().append(_.map(_.filter(Configurator.connectors.filters, function(e) {
                        return e.value ? !1 : _.intersection(e.supports, n.supports).length > 0
                    }), function(n) {
                        var e = $("<li><h2>" + n.title + "</h2></li>");
                       
                        return $options = $("<ul></ul>").append(_.map(n.options, function(n, e) {
                            return $("<li></li>").append($("<label></label>").append($('ul#criteria li:first ul > li > label > input[type="checkbox"]').is(':checked') ? 
                                    (n.preselect > 0 ? 
                                        (n.value=='Cat8' ? 
                                            $('<input value="' + n.value + '" type="checkbox" />').prop("checked", n.preselect).prop("disabled",false) :
                                            $('<input value="' + n.value + '" type="checkbox" />').prop("checked", n.preselect).prop("disabled", n.preselect)) : 
                                        (n.value=='Cat8'?
                                            $('<input value="' + n.value + '" type="checkbox" />').prop("disabled",false) : 
                                                $('<input value="' + n.value + '" type="checkbox" />').prop("disabled", "true"))) :
                                    (n.req > 0 ? 
                                        $('<input value="' + n.value + '" type="checkbox" />').prop("checked", n.preselect).prop("disabled", n.preselect) : 
                                        $('<input value="' + n.value + '" type="checkbox" />').prop("checked", n.preselect))).append((n.preselect > 0 ? 
                                                $("<span class='chk_selected'>" + n.option + "</span>") : 
                                                $("<span>" + n.option + "</span>"))))

                            })).appendTo(e), e

                }));
                    i.find("input:checkbox:first").trigger("change")
                                  
                   
    
                     if ($(":checkbox[value='Cat8']").is(':checked'))
                    {

                     $(":checkbox[value='TERA']").attr("disabled","true");
                     $(":checkbox[value='GG45']").attr("disabled","true");

                     }
                    $("input[value='Cat8']").click(function() {
                        if ($(":checkbox[value='Cat8']").is(':checked')) {
                            $(":checkbox[value='TERA']").prop({ disabled: true, checked: false });
                            $(":checkbox[value='GG45']").prop({ disabled: true, checked: false });
                            con_cat8 = true;
                        } else {
                            $(":checkbox[value='TERA']").prop("disabled", false);
                            $(":checkbox[value='GG45']").prop("disabled", false);
                            con_cat8 = false;
                        }
                        $('#configure').submit();
                    });
                    
                    if(($('ul#criteria li:nth-child(2) ul > li > label > input[type="checkbox"]').is(':checked') && $('ul#criteria li:nth-child(7) ul > li:nth-child(2) > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(3) ul > li > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(4) ul > li > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(5) ul > li > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(6) ul > li > label > input[type="checkbox"]').is(':checked')) || ($('ul#criteria li:nth-child(2) ul > li > label > input[type="checkbox"]').is(':checked') && $('ul#criteria li:nth-child(7) ul > li:nth-child(2) > label > input[type="checkbox"]').is(':checked') && $('ul#criteria li:nth-child(6) ul > li > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(3) ul > li > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(4) ul > li > label > input[type="checkbox"]').is(':checked') && !$('ul#criteria li:nth-child(5) ul > li > label > input[type="checkbox"]').is(':checked'))){
                        if (!$(":checkbox[value='Cat8']").is(':checked')){
                            $('#summary-required').empty();
                            $("#summary-suggested").find("tr:first-child ~ tr").remove().end();
                        }
                    }
                };
                s(), $("#configure").find("button, input").prop("disabled", !0), $("body").addClass("bom")
            }).fail(function() {
                alert("no match found"), $("#configure").find("button, input").prop("disabled", !1)
            })
        }
    }).on("click", "#configure button[type='reset']", function(n) {
        n.preventDefault(), $(this).closest("form").trigger("reset")
    }).on("reset", "#configure", function(n) {
        n.preventDefault(), $("#criteria input:checked").prop("checked", !1).first().trigger("change"), window.scrollTo(0, 0)
    }).on("click", "#family", function(n) {
        if(!con_cat8){
            con_cat8 =true;
        }
        $("body").hasClass("bom") && ($("#configure").find("button, input").prop("disabled", !1), $("body").removeClass("bom"))
                          
           if (($('ul#criteria li:first ul > li > label > input[type="checkbox"]').is(':checked')) || ($('ul#criteria li:first ul > li > label > input[type="checkbox"]').is(':checked') && $('ul#criteria li:nth-child(6) ul > li > label > input[type="checkbox"]').is(':checked'))) {
                    $('input.requires:not(:checked)').attr('disabled', 'disabled');
                    $('input.provides:not(:checked)').attr('disabled', 'disabled');
                } else if ($('ul#criteria li:nth-child(2) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(3) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(4) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(5) ul > li > label > input[type="checkbox"]').is(':checked') || $('ul#criteria li:nth-child(7) ul > li > label > input[type="checkbox"]').is(':checked')

                ) {
                    $('ul#criteria li:first ul > li > label > input[type="checkbox"]').attr('disabled', 'disabled');
                } else {
                    $('input.requires').removeAttr('disabled');
                    $('input.provides').removeAttr('disabled');
                }  
    })
}, jQuery, jQuery(document));