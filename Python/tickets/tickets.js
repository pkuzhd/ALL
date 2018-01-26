(function(C) {
	jQuery.extend({
		ht_getcookie: function(W) {
			var k = document.cookie.indexOf(W);
			var i = document.cookie.indexOf(";", k);
			return k == -1 ? "" : unescape(document.cookie.substring(k + W.length + 1, (i > k ? i : document.cookie.length)))
		},
		ht_setcookie: function(aa, Z, Y, X, k, W) {
			var i = new Date();
			i.setTime(i.getTime() + Y * 1000);
			document.cookie = escape(aa) + "=" + escape(Z) + (i ? "; expires=" + i.toGMTString() : "") + (X ? "; path=" + X : "; path=/") + (k ? "; domain=" + k : "") + (W ? "; secure" : "")
		},
		textFocus: function(W) {
			var k, i, W = W === undefined ? 0 : parseInt(W);
			this.each(function() {
				if (!this.setSelectionRange) {
					k = this.createTextRange();
					W === 0 ? k.collapse(false) : k.move("character", W);
					k.select()
				} else {
					i = this.value.length;
					W === 0 ? this.setSelectionRange(i, i) : this.setSelectionRange(W, W)
				}
				this.focus()
			});
			return this
		}
	});
	var w = [];
	var D = [];
	var E = [];
	var G = [];
	var v = 0;
	var y = 0;
	var A = 0;
	var S = 0;
	var U = false;
	var g = false;
	var H = false;
	var z = 0;
	var I = null;
	var m = -1;
	var N = {};
	var f = [];
	var e = [];
	var d = [];
	var b = [];
	var V = [];
	var F = new Array("a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z");
	var j = [];
	var x = false;
	var c = [];
	for (var R = 0; R < 26; R++) {
		c[R] = []
	}
	var P = [];
	for (var T = 0; T < 5; T++) {
		P[T] = []
	}
	var t = [];
	var s = [];
	var q = [];
	var p = [];
	var o = [];
	var K = [];
	var a = false;
	var L = true;
	var u = 12;
	var h = "简码/汉字";
	var n = "简码/汉字";
	var r = "inp-txt_select";
	var l = "inp-txt";
	var B = false;
	var J = null;
	var Q = null;
	var M = false;
	var O = C.ht_getcookie("hj_favcity");
	C.stationFor12306 = {
		bindInputs: [],
		get_initInputValue: function() {
			return h
		},
		get_initTopInputValue: function() {
			return n
		},
		city_Bind: function(k) {
			if (k.length == 0) {
				return
			}
			var i = "";
			C.each(k, function(W) {
				if (O == k[W][2]) {
					i += "<div class='cityline' id='citem_" + W + "' cturn='" + k[W][6] + "'><span class='ralign'><b>" + k[W][1] + "</b></span></div>\n"
				} else {
					i += "<div class='cityline' id='citem_" + W + "' cturn='" + k[W][6] + "'><span class='ralign'>" + k[W][1] + "</span><span style='float:right;' class='ralign'>" + k[W][3] + "</span></div>\n"
				}
			});
			C("#panel_cities").html(i);
			C(".cityline").mouseover(function() {
				C.stationFor12306.city_shiftSelect(this)
			}).click(function() {
				C.stationFor12306.city_confirmSelect();
				E = C.stationFor12306.filterCity("");
				C.stationFor12306.city_showlist(0)
			});
			C.stationFor12306.city_shiftSelect(C("#citem_0"))
		},
		city_changeSelectIndex: function(i) {
			var k = A + i;
			if (k == -1) {
				C.stationFor12306.city_showlist(z - 1);
				C.stationFor12306.city_shiftSelect(C("#citem_" + (G.length - 1)))
			} else {
				if (k == G.length) {
					C.stationFor12306.city_showlist(z + 1);
					C.stationFor12306.city_shiftSelect(C("#citem_0"))
				} else {
					C.stationFor12306.city_shiftSelect(C("#citem_" + k))
				}
			}
		},
		city_confirmSelect: function() {
			I.val(S[1]);
			curObjCode.val(S[2]);
			if (B) {
				C.stationFor12306.setStationInCookies(S[1], S[2])
			}
			C("#form_cities").css("display", "none");
			C("#form_cities2").css("display", "none");
			C("#form_cities3").css("display", "none");
			m = -1;
			y = 0;
			C.stationFor12306.setStationStyle();
			if (L) {
				C.stationFor12306.LoadJS(S[2])
			}
			if (J) {
				J(I, curObjCode)
			}
		},
		city_shiftSelect: function(k) {
			if (v != k) {
				if (v != 0) {
					C(v).removeClass("citylineover").addClass("cityline").css("backgroundColor", "white")
				}
				if (k != 0) {
					try {
						v = k;
						var i = C(v).removeClass("cityline").addClass("citylineover").css("backgroundColor", "#c8e3fc");
						A = Number(i.attr("id").split("_")[1]);
						S = w[Number(i.attr("cturn"))];
						C("#cityid").val(S[2])
					} catch (W) {}
				}
			}
		},
		city_shiftSelectInLi: function(i) {
			if (y != i) {
				if (y != 0) {
					C(y).removeClass("ac_over").addClass("ac_odd")
				}
				if (i != 0) {
					try {
						y = i;
						C(y).removeClass("ac_odd").addClass("ac_over")
					} catch (k) {}
				}
			}
		},
		js: function(W) {
			var k;
			for (k = 1; k <= 7; k++) {
				if (C("#nav_list" + k).attr("class")) {
					C("#ul_list" + k).css("display", "none");
					C("#nav_list" + k).removeClass("action")
				}
			}
			for (k = 1; k <= 7; k++) {
				if (k == W) {
					C("#ul_list" + k).css("display", "block");
					C("#nav_list" + k).addClass("action");
					if (k == 1 || k == 7) {
						C("#flip_cities2").css("display", "none")
					}
					if (k > 1 && k < 7) {
						var Y = C.stationFor12306.tHtmlGetCityName(W - 1, -1, 0);
						if (Y > u) {
							var X = Math.ceil(Y / u);
							if (X > 1) {
								C.stationFor12306.pageDesigh(X, 0, k)
							}
							C("#flip_cities2").css("display", "block")
						} else {
							C("#flip_cities2").css("display", "none")
						}
					} else {
						I.focus()
					}
				} else {
					C("#ul_list" + k).css("display", "none");
					C("#nav_list" + k).removeClass("action")
				}
			}
			if (1 != W) {
				C(".ac_even").on("mouseover", function() {
					C.stationFor12306.city_shiftSelectInLi(this)
				}).on("click", function() {
					I.val(C(this).text());
					curObjCode.val(C(this).attr("data"));
					if (B) {
						C.stationFor12306.setStationInCookies(C(this).text(), C(this).attr("data"))
					}
					C("#form_cities2").css("display", "none");
					m = -1;
					y = 0;
					C.stationFor12306.setStationStyle();
					if (L) {
						C.stationFor12306.LoadJS(C(this).attr("data"))
					}
					if (J) {
						J(I, curObjCode)
					}
				})
			}
		},
		tHtmlGetCityName: function(k, i, X) {
			switch (k) {
				case 0:
					if (i == -1) {
						return D.length
					}
					if (i == -2) {
						return D
					}
					return D[i];
					break;
				case 1:
					if (i == -1) {
						return c[3].length
					}
					if (i == -2) {
						return f
					}
					if (f.length > u) {
						var W = Math.ceil((f.length) / u);
						if (W > 1) {
							t = f.slice(u * (X), Math.min(u * (X + 1), f.length));
							return t[i]
						}
					}
					return f[i];
					break;
				case 2:
					if (i == -1) {
						return c[7].length
					}
					if (i == -2) {
						return e
					}
					if (e.length > u) {
						var W = Math.ceil((e.length) / u);
						if (W > 1) {
							s = e.slice(u * (X), Math.min(u * (X + 1), e.length));
							return s[i]
						}
					}
					return e[i];
					break;
				case 3:
					if (i == -1) {
						return c[11].length
					}
					if (i == -2) {
						return d
					}
					if (d.length > u) {
						var W = Math.ceil((d.length) / u);
						if (W > 1) {
							q = d.slice(u * (X), Math.min(u * (X + 1), d.length));
							return q[i]
						}
					}
					return d[i];
					break;
				case 4:
					if (i == -1) {
						return c[18].length
					}
					if (i == -2) {
						return b
					}
					if (b.length > u) {
						var W = Math.ceil((b.length) / u);
						if (W > 1) {
							p = b.slice(u * (X), Math.min(u * (X + 1), b.length));
							return p[i]
						}
					}
					return b[i];
					break;
				case 5:
					if (i == -1) {
						return c[24].length
					}
					if (i == -2) {
						return V
					}
					if (V.length > u) {
						var W = Math.ceil((V.length) / u);
						if (W > 1) {
							o = V.slice(u * (X), Math.min(u * (X + 1), V.length));
							return o[i]
						}
					}
					return V[i];
					break;
				default:
					return "error";
					break
			}
		},
		closeShowCity: function() {
			C("#form_cities2").css("display", "none");
			m = -1;
			y = 0;
			C.each(C.stationFor12306.bindInputs, function(Y, X) {
				var W = "#" + X;
				var k = "#" + X + "Text";
				var i = C(k).val();
				if ("" == i) {
					C(k).val(h);
					C.stationFor12306.from_to_station_class_gray(C(k));
					C(W).val("")
				}
			})
		},
		showAllCity: function() {
			var ab = "";
			var k = "440px";
			if (B) {
				k = "400px"
			}
			ab = '<div class="com_hotresults" id="thetable" style="width:' + k + '"><div style="width:100%;"><div class="ac_title"><span>拼音支持首字母输入</span><a class="ac_close" style="cursor:pointer" title="关闭" onclick="$.stationFor12306.closeShowCity()"></a></div><ul class="AbcSearch clx" id="abc">';
			if (B) {
				ab = ab + '<li class="action" index="7" method="liHotTab"  onclick="$.stationFor12306.js(7)" id="nav_list7">常用</li>'
			}
			ab = ab + '<li index="1" method="liHotTab"  onclick="$.stationFor12306.js(1)" id="nav_list1">热门</li><li index="2" method="liHotTab"  onclick="$.stationFor12306.js(2)" id="nav_list2">ABCDE</li><li index="3" method="liHotTab"  onclick="$.stationFor12306.js(3)" id="nav_list3">FGHIJ</li><li index="4" method="liHotTab"  onclick="$.stationFor12306.js(4)" id="nav_list4">KLMNO</li><li index="5" method="liHotTab"  onclick="$.stationFor12306.js(5)" id="nav_list5">PQRST</li><li index="6" method="liHotTab"  onclick="$.stationFor12306.js(6)" id="nav_list6">UVWXYZ</li></ul>';
			if (B) {
				ab += '<ul class="popcitylist" style="overflow: auto;max-height: 280px;height: 191px;" method="hotData" id="ul_list7">';
				var ac = C.stationFor12306.getStationInCookies();
				var Y = ac.length;
				if (Y > 2) {
					M = true;
					for (var ad = 0; ad < Y; ad++) {
						ab += '<li class="ac_even"   title="' + ac[ad][0] + '" data="' + ac[ad][1] + '">' + ac[ad][0] + "</li>"
					}
				}
				ab += "</ul>"
			}
			ab += '<ul class="popcitylist" style="overflow: auto;max-height: 280px;height: 191px;display:none;" method="hotData" id="ul_list1">';
			var X = C.stationFor12306.tHtmlGetCityName(0, -1, 0);
			var aa = "";
			if (!B) {
				aa = " openLi"
			}
			for (var ad = 0; ad < X; ad++) {
				ab += '<li class="ac_even' + aa + '"   title="' + C.stationFor12306.tHtmlGetCityName(0, ad, 0)[1] + '" data="' + C.stationFor12306.tHtmlGetCityName(0, ad, 0)[2] + '">' + C.stationFor12306.tHtmlGetCityName(0, ad, 0)[1] + "</li>"
			}
			ab += "</ul>";
			for (var ae = 2; ae <= 6; ae++) {
				var Z = ae - 1;
				var i = C.stationFor12306.tHtmlGetCityName(Z, -1, 0);
				if (i > u) {
					var W = Math.ceil((i) / u);
					if (W > 1) {
						ab += '<div id="ul_list' + ae + '">';
						C.stationFor12306.pageDesigh(W, 0, ae)
					}
					C("#flip_cities2").css("display", "block")
				} else {
					ab += '<ul  class="popcitylist" style="overflow: auto; max-height: 260px; height: 191px;display:none;" id="ul_list' + ae + '">';
					C("#flip_cities2").css("display", "none");
					var aa = "";
					if (!B) {
						aa = " openLi"
					}
					for (var ad = 0; ad < C.stationFor12306.tHtmlGetCityName(Z, -1, 0); ad++) {
						ab += '<li class="ac_even' + aa + '"   title="' + C.stationFor12306.tHtmlGetCityName(Z, ad, 0)[1] + '" data="' + C.stationFor12306.tHtmlGetCityName(Z, ad, 0)[2] + '">' + C.stationFor12306.tHtmlGetCityName(Z, ad, 0)[1] + "</li>"
					}
				}
				ab += "</div>"
			}
			ab += '<div id="flip_cities2"> 翻页控制区</div>';
			ab += "</div>";
			C("#panel_cities2").html(ab);
			C("#thetable").on("click", function() {
				if (C("#form_cities2").css("display") == "block") {
					if (m == 1 | m == 0) {
						m == -1
					}
					I.select()
				}
			});
			C("#form_cities").on("click", function() {
				if (C("#form_cities").css("display") == "block") {
					if (m == 1 | m == 0) {
						m == -1
					}
					I.select()
				}
			});
			C(".ac_even").on("mouseover", function() {
				C.stationFor12306.city_shiftSelectInLi(this)
			}).on("click", function() {
				I.val(C(this).text());
				curObjCode.val(C(this).attr("data"));
				if (B) {
					C.stationFor12306.setStationInCookies(C(this).text(), C(this).attr("data"))
				}
				C("#form_cities2").css("display", "none");
				m = -1;
				y = 0;
				C.stationFor12306.setStationStyle();
				if (L) {
					C.stationFor12306.LoadJS(C(this).attr("data"))
				}
				if (J) {
					J(I, curObjCode)
				}
			});
			C("#flip_cities2").css("display", "none");
			return w
		},
		LoadJS: function(W) {
			if (((typeof(mm_addjs) != "undefined")) && ("" != mm_addjs) && (mm_addjs == 1)) {
				var k = document.getElementsByTagName("HEAD").item(0);
				var i = document.createElement("SCRIPT");
				i.src = mm_srcjs + W + ".js";
				i.type = "text/javascript";
				k.appendChild(i)
			}
		},
		addZMHtml: function(X, Y) {
			var W = "";
			if (X && X.length > 0) {
				var Z = X[0][0].charAt(0);
				W += '<ul  class="popcitylist" style="overflow: auto; max-height: 260px; " >';
				W += '<li class="ac_letter">' + Z.toUpperCase() + "</li>";
				for (var i = 0; i < 12; i++) {
					var k = X[i];
					if (k) {
						W += '<li class="ac_even' + Y + '"   title="' + k[1] + '" data="' + k[2] + '">' + k[1] + "</li>"
					} else {
						W += '<li class="ac_even' + Y + '" </li>'
					}
				}
				W += "</ul>"
			}
			return W
		},
		pageDesigh: function(Z, ac, ad) {
			var W = "";
			if (Z > 1) {
				if (ac == -1) {
					ac = (Z - 1)
				} else {
					if (ac == Z) {
						ac = 0
					}
				}
				var ab = "";
				if (!B) {
					ab = " openLi"
				}
				for (var X = 2; X <= 6; X++) {
					if (X == ad) {
						var aa = P[X - 2];
						for (var i = 0; i < aa.length; i++) {
							K = aa[i].slice(ac * u, (ac + 1) * u);
							W += C.stationFor12306.addZMHtml(K, ab)
						}
					}
				}
				C("#ul_list" + ad).html(W);
				C("#ul_list" + ad).css("height", 270);
				if (W) {
					var Y = (ac == 0) ? "&laquo;&nbsp;上一页" : "<a style='cursor:pointer'    class='cityflip' onclick='$.stationFor12306.pageDesigh(" + Z + "," + (ac - 1) + "," + ad + ");return false;'>&laquo;&nbsp;上一页</a>";
					Y += "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;";
					Y += (ac == Z - 1) ? "下一页&nbsp;&raquo;" : "<a style='cursor:pointer' class='cityflip'  onclick='$.stationFor12306.pageDesigh(" + Z + "," + (ac + 1) + "," + ad + ")'>下一页&nbsp;&raquo;</a>";
					C("#flip_cities2").html(Y)
				} else {
					C("#flip_cities2").html("")
				}
				if (m == 1 | m == 0 | m == 2) {
					m == -1
				}
				if (I) {
					I.select()
				}
			} else {}
			C(".ac_even").on("mouseover", function() {
				C.stationFor12306.city_shiftSelectInLi(this)
			}).on("click", function() {
				I.val(C(this).text());
				curObjCode.val(C(this).attr("data"));
				if (B) {
					C.stationFor12306.setStationInCookies(C(this).text(), C(this).attr("data"))
				}
				C("#form_cities2").css("display", "none");
				m = -1;
				y = 0;
				C.stationFor12306.setStationStyle();
				if (L) {
					C.stationFor12306.LoadJS(C(this).attr("data"))
				}
				if (J) {
					J(I, curObjCode)
				}
			})
		},
		filterCity: function(Z) {
			if (Z.length == 0) {
				C("#top_cities").html(n);
				return w
			}
			var Y = /<\/?[^>]*>/g;
			Z = Z.replace(Y, "");
			var W = [];
			var k = /[^A-z]/.test(Z);
			for (var X = 0; X < w.length; X++) {
				if (C.stationFor12306.isMatchCity(w[X], Z, k)) {
					W.push(w[X])
				}
			}
			if (W.length > 0) {
				C("#top_cities").html('按"<font color=red>' + Z + '</font>"检索：');
				return W
			} else {
				C("#top_cities").html("无法匹配:<font color=red>" + Z + "</font>");
				return []
			}
		},
		replaceChar: function(i, W, k) {
			return i.substr(0, W) + k + i.substr(W + 1, i.length - 1)
		},
		isMatchCity: function(Z, ac, W) {
			var ac = ac.toLowerCase();
			var k = [Z[4].toLowerCase(), Z[1], Z[3].toLowerCase()];
			var ab = -1;
			var Y = -1;
			if (W) {
				ac = ac.split("");
				for (var X = 0; X < ac.length; X++) {
					var ae = k[1].indexOf(ac[X]);
					if (ae > ab && ae <= X) {
						k[1] = C.stationFor12306.replaceChar(k[1], ae, "-");
						ab = ae
					} else {
						return false
					}
				}
			} else {
				ac = ac.split("");
				var i = true;
				var aa = true;
				for (var X = 0; X < ac.length; X++) {
					var ae = k[0].indexOf(ac[X]);
					if (ae > ab && ae <= X) {
						k[0] = C.stationFor12306.replaceChar(k[0], ae, "-");
						ab = ae
					} else {
						i = false;
						break
					}
				}
				for (var X = 0; X < ac.length; X++) {
					var ad = k[2].indexOf(ac[X]);
					if (ad > Y && ad <= X) {
						k[2] = C.stationFor12306.replaceChar(k[2], ad, "-");
						Y = ad
					} else {
						aa = false;
						break
					}
				}
				if ((i == false) && (aa == false)) {
					return false
				}
			}
			return true
		},
		city_showlist_page: function(ad, Y) {
			var Z = "";
			Z += '<div class="citypage">';
			Z += (ad == 0) ? "" : '<a href="#" class="pagetxt" onclick="$.stationFor12306.city_showlist(' + (ad - 1) + ');return false;"><<</a>';
			var ae = ad + 1;
			var aa = Y;
			var ab = 2;
			var ac = 5;
			var k = (ae - ab) > 0 ? (ae + ab > aa ? aa - ac + 1 : ae - ab) : 1;
			var W = k + ac > aa ? aa + 1 : k + ac;
			if (aa < ac) {
				for (var X = 1; X < aa + 1; X++) {
					if (ae == X) {
						Z += "<a href='' class='cur' onclick='$.stationFor12306.city_showlist(" + (X - 1) + ");return false;'>" + (X) + "</a>"
					} else {
						Z += "<a href='' onclick='$.stationFor12306.city_showlist(" + (X - 1) + ");return false;'>" + (X) + "</a>"
					}
				}
			} else {
				for (var X = k; X < W; X++) {
					if (ae == X) {
						Z += "<a href='' class='cur' onclick='$.stationFor12306.city_showlist(" + (X - 1) + ");return false;'>" + (X) + "</a>"
					} else {
						Z += "<a href='' onclick='$.stationFor12306.city_showlist(" + (X - 1) + ");return false;'>" + (X) + "</a>"
					}
				}
			}
			Z += (ad == Y - 1) ? "" : '<a href="" class="pagetxt" onclick="$.stationFor12306.city_showlist(' + (ad + 1) + ');return false;">>></a>';
			Z += "</div>";
			return Z
		},
		city_showlist: function(W) {
			if (E.length > 6) {
				var k = Math.ceil((E.length) / 6);
				if (W == -1) {
					W = (k - 1)
				} else {
					if (W == k) {
						W = 0
					}
				}
				G = E.slice(6 * (W), Math.min(6 * (W + 1), E.length));
				C.stationFor12306.city_Bind(G);
				var i = "";
				i += C.stationFor12306.city_showlist_page(W, k);
				C("#flip_cities").html(i);
				C("#flip_cities").css("display", "block")
			} else {
				W = 0;
				G = E;
				C.stationFor12306.city_Bind(G);
				C("#flip_cities").css("display", "none")
			}
			z = W;
			if (C("#form_cities").css("display") == "block") {
				a = true;
				I.focus()
			}
		},
		fixDivBugInIE6: function(i) {
			try {
				i.bgiframe();
				if (i.width() > C("> ul", i).width()) {
					i.css("overflow", "hidden")
				} else {
					C("> iframe.bgiframe", i).width(C("> ul", i).width());
					i.css("overflow", "scroll")
				}
				if (i.height() > C("> ul", i).height()) {
					i.css("overflow", "hidden")
				} else {
					C("> iframe.bgiframe", i).height(C("> ul", i).height());
					i.css("overflow", "scroll")
				}
			} catch (k) {}
		},
		clearStation: function(i) {
			m = -1;
			var W = I.val();
			var X = curObjCode.val();
			if (W == "" || X == "") {
				I.val("");
				curObjCode.val("")
			} else {
				var k = W + "|" + X;
				if (typeof(station_names) != "undefined") {
					if (station_names.indexOf(k) == -1) {
						I.val("");
						curObjCode.val("")
					} else {
						if ("click" == i) {
							I.select();
							if (C("#form_cities").is(":hidden")) {
								C("#form_cities2").css("display", "block")
							}
						}
					}
				} else {
					I.val("");
					curObjCode.val("")
				}
			}
		},
		MapCityID: function(W) {
			for (var k = 0; k < w.length; k++) {
				if (w[k][1] == W) {
					return w[k][2]
				}
			}
			return 0
		},
		MapCityName: function(k) {
			for (var W = 0; W < w.length; W++) {
				if (w[W][2] == k) {
					return w[W][1]
				}
			}
			return ""
		},
		SetISPos: function(Y) {
			if (Q) {
				Q(C("#form_cities"), C("#form_cities2"))
			} else {
				C("#form_cities").css("left", Y.position().left);
				C("#form_cities").css("top", Y.position().top + Y.height() + 12);
				C("#form_cities2").css("left", Y.position().left);
				C("#form_cities2").css("top", Y.position().top + Y.height() + 12)
			}
			var X = Y.offset().top;
			var i = C("#search_div");
			var k = C("#choice_div");
			i.css("top", X);
			k.css("top", X);
			var W = Y.offset().left;
			i.css("left", W);
			k.css("left", W)
		},
		myHandlerFg: function(i) {
			if (i == null) {
				i.keyCode = 9
			} else {
				if (!i.which && i.which == 13) {
					i.preventDefault()
				} else {
					if (i.which && i.keyCode == 13) {
						i.which = 9
					}
				}
			}
		},
		myHandler2: function(i) {
			if (i == null) {
				i = window.event;
				i.returnValue = false
			} else {
				if (i.which && i.which == 13) {
					var W = document.getElementById("Upload_Data3");
					if (document.createEvent) {
						var k = document.createEvent("MouseEvents");
						k.initEvent("click", true, false);
						W.dispatchEvent(k)
					} else {
						if (document.createEventObject) {
							W.fireEvent("onclick")
						}
					}
				} else {
					if (!i.which && i.which == 13) {
						i.preventDefault()
					}
				}
			}
		},
		from_to_station_class_plain: function(i) {
			if (l && l != "") {
				i.removeClass(l)
			}
			if (r && r != "") {
				i.addClass(r)
			}
		},
		from_to_station_class_gray: function(i) {
			if (r && r != "") {
				i.removeClass(r)
			}
			if (l && l != "") {
				i.addClass(l)
			}
		},
		setStationStyle: function() {
			var i = I.val();
			if (i == "") {
				I.val(h);
				C.stationFor12306.from_to_station_class_gray(I);
				curObjCode.val("")
			} else {
				C.stationFor12306.from_to_station_class_plain(I)
			}
		},
		setCurValue: function() {
			I.val(S[1]);
			curObjCode.val(S[2])
		},
		bindEvent: function(i) {
			var W = "#" + i;
			var k = "#" + i + "Text";
			C(k).keydown(function(Y) {
				I = C(k);
				curObjCode = C(W);
				m = 0;
				a = true;
				L = true;
				C("#form_cities2").css("display", "none");
				y = 0;
				var X = C(k).width();
				if (-[1, ]) {
					X = X - 4
				}
				X = X < 220 ? 220 : X;
				C("#form_cities").css("width", X);
				C("#form_cities").css("display", "block");
				C(".AbcSearch li").removeClass("action");
				C(".popcitylist").css("display", "none");
				if (M && B) {
					C("#ul_list7").css("display", "block");
					C("#nav_list7").addClass("action")
				} else {
					C("#nav_list1").addClass("action");
					C("#ul_list1").css("display", "block")
				}
				C("#flip_cities2").css("display", "none");
				C(".ac_even").removeClass("ac_over").addClass("ac_odd");
				Y = Y || window.event;
				if (Y.keyCode == 40) {
					C.stationFor12306.city_changeSelectIndex(1);
					C("#form_cities").css("display", "block");
					C.stationFor12306.SetISPos(I);
					C.stationFor12306.setCurValue()
				} else {
					if (Y.keyCode == 38) {
						C.stationFor12306.city_changeSelectIndex(-1);
						C.stationFor12306.setCurValue();
						C("#form_cities").css("display", "block");
						C.stationFor12306.SetISPos(I)
					} else {
						if (Y.keyCode == 13) {
							C.stationFor12306.city_confirmSelect();
							if (document.addEventListener) {
								document.addEventListener("keypress", C.stationFor12306.myHandlerFg, true)
							} else {
								evt = window.event;
								evt.keyCode = 9
							}
						}
					}
				}
			}).focus(function() {
				L = true;
				if (a) {
					C("#form_cities2").css("display", "none");
					y = 0;
					a = false;
					m = -1
				} else {
					if (m == -1) {
						C(".AbcSearch li").removeClass("action");
						C(".popcitylist").css("display", "none");
						C("#flip_cities2").css("display", "none");
						if (M && B) {
							C("#ul_list7").css("display", "block");
							C("#nav_list7").addClass("action")
						} else {
							C("#nav_list1").addClass("action");
							C("#ul_list1").css("display", "block")
						}
						C(".ac_even").removeClass("ac_over").addClass("ac_odd");
						C("#form_cities2").css("display", "block");
						for (var X = 2; X <= 6; X++) {
							C("#ul_list" + X).css("height", 0)
						}
					}
				}
				I = C(k);
				curObjCode = C(W);
				m = 0;
				U = true;
				C.stationFor12306.SetISPos(I)
			}).blur(function() {
				I = C(k);
				curObjCode = C(W);
				m = 0;
				a = false;
				L = true;
				if (!g && !H) {
					C.stationFor12306.clearStation("blur");
					U = false;
					C("#form_cities").css("display", "none");
					C("#form_cities2").css("display", "none");
					m = -1;
					y = 0;
					E = C.stationFor12306.filterCity("");
					C.stationFor12306.city_showlist(0);
					C.stationFor12306.setStationStyle()
				}
			}).keyup(function(X) {
				I = C(k);
				curObjCode = C(W);
				m = 0;
				a = true;
				X = X || window.event;
				if (X.keyCode != 40 && X.keyCode != 38 && X.keyCode != 37 && X.keyCode != 39 && X.keyCode != 13 && X.keyCode != 9) {
					E = C.stationFor12306.filterCity(I.val());
					C.stationFor12306.city_showlist(0)
				}
			}).click(function() {
				C.stationFor12306.clearStation("click")
			});
			C.stationFor12306.bindInputs.push(i)
		},
		getStationInCookies: function() {
			var W = [];
			var k = C.ht_getcookie("_city_name_save_station");
			if (k) {
				var i = k.split(",");
				if (i && i.length > 0) {
					C.each(i, function(aa, Z) {
						var X = Z.split("#");
						var Y = [];
						Y[0] = X[0];
						Y[1] = X[1];
						W[aa] = Y
					})
				}
			}
			return W
		},
		setStationInCookies: function(af, W) {
			var ac = C.stationFor12306.getStationInCookies();
			var Z = [];
			var ag = ac.length;
			var Y = true;
			var ah = 10;
			for (var aa = 0; aa < ag; aa++) {
				if (ac[aa][0] == af && ac[aa][1] == W) {
					Y = false
				}
				Z.push(ac[aa])
			}
			if (Y) {
				Z.push([af, W])
			}
			var ab = Z;
			var X = "";
			var ad = ab.length;
			var aa = 0;
			if (ad > ah) {
				aa = 1
			}
			var i = aa;
			if (ad > 1) {
				C("#ul_list7").html("");
				M = true
			}
			var ae = "";
			for (; aa < ad; aa++) {
				if (aa > i) {
					X += ","
				}
				X += ab[aa][0] + "#" + ab[aa][1];
				if (M && B) {
					ae += '<li class="ac_even" onmouseover="$.stationFor12306.city_shiftSelectInLi(this);" onclick="$.stationFor12306.li_click(this);"   title="' + ab[aa][0] + '" data="' + ab[aa][1] + '">' + ab[aa][0] + "</li>"
				}
			}
			if (M && B) {
				C("#ul_list7").html(ae)
			}
			C.ht_setcookie("_city_name_save_station", X, 365 * 24 * 60 * 60)
		},
		li_click: function(i) {
			I.val(C(i).text());
			curObjCode.val(C(i).attr("data"));
			if (B) {
				C.stationFor12306.setStationInCookies(C(i).text(), C(i).attr("data"))
			}
			C("#form_cities2").css("display", "none");
			m = -1;
			y = 0;
			C.stationFor12306.setStationStyle();
			if (L) {
				C.stationFor12306.LoadJS(C(i).attr("data"))
			}
			if (J) {
				J(I, curObjCode)
			}
		},
		init: function(ac, ad) {
			if (typeof(ad) != "undefined") {
				if (typeof(ad._init_input) != "undefined") {
					h = ad._init_input
				}
				if (typeof(ad._top_4_initInput) != "undefined") {
					n = ad._top_4_initInput
				}
				if (typeof(ad.confirmCallBack) != "undefined") {
					J = ad.confirmCallBack
				}
				if (typeof(ad._selected_class) != "undefined") {
					r = ad._selected_class
				}
				if (typeof(ad._unselected_class) != "undefined") {
					l = ad._unselected_class
				}
				if (typeof(ad._12306_openFavorite) != "undefined") {
					B = ad._12306_openFavorite
				}
				if (typeof(ad.position) != "undefined") {
					Q = ad.position
				}
			}
			if (typeof(station_names) != "undefined") {
				var Z = station_names.split("@");
				for (var Y = 0; Y < Z.length; Y++) {
					var ab = Z[Y];
					var aa = ab.toString().charAt(0);
					for (var X in F) {
						if (aa == F[X]) {
							c[X].push(ab.split("|"))
						}
					}
					if (ab.length > 0) {
						ab = ab.split("|");
						if (O != "" && ab[2] == O) {
							favcity = ab;
							w.unshift(ab);
							if (Y > 6) {
								w.push(ab)
							}
						} else {
							w.push(ab)
						}
					}
				}
				f = c[0].concat(c[1]).concat(c[2]).concat(c[3]).concat(c[4]);
				e = c[5].concat(c[6]).concat(c[7]).concat(c[8]).concat(c[9]);
				d = c[10].concat(c[11]).concat(c[12]).concat(c[13]).concat(c[14]);
				b = c[15].concat(c[16]).concat(c[17]).concat(c[18]).concat(c[19]);
				V = c[20].concat(c[21]).concat(c[22]).concat(c[23]).concat(c[24]).concat(c[25]);
				P[0] = [c[0], c[1], c[2], c[3], c[4]];
				P[1] = [c[5], c[6], c[7], c[8], c[9]];
				P[2] = [c[10], c[11], c[12], c[13], c[14]];
				P[3] = [c[15], c[16], c[17], c[18], c[19]];
				P[4] = [c[20], c[22], c[23], c[24], c[25]];
				for (var Y = 0; Y < w.length; Y++) {
					w[Y].push(Y)
				}
			}
			if (typeof(favorite_names) != "undefined") {
				var W = favorite_names.split("@");
				for (var Y = 0; Y < W.length; Y++) {
					var ab = W[Y];
					if (ab.length > 0) {
						ab = ab.split("|");
						D.push(ab)
					}
				}
				for (var Y = 0; Y < D.length; Y++) {
					D[Y].push(Y)
				}
			}
			E = C.stationFor12306.filterCity("");
			C.stationFor12306.city_showlist(0);
			C.stationFor12306.showAllCity();
			a = false;
			C.stationFor12306.fixDivBugInIE6(C("#form_cities"));
			C.stationFor12306.fixDivBugInIE6(C("#form_cities2"));
			if (ac && ac.length > 0) {
				C.each(ac, function(k, i) {
					C.stationFor12306.bindEvent(i)
				})
			}
			C("#form_cities").mousedown(function() {
				g = true
			}).mouseup(function() {
				g = false
			});
			C("#form_cities2").mousedown(function() {
				H = true
			}).mouseup(function() {
				H = false
			})
		}
	}
})(jQuery);
(function() {
	$.stopStation = function(a) {
		var b = this;
		b.init = function() {
			b.options = $.extend({}, $.stopStation.defaultOptions, a);
			if (null == b.options.url || null == b.options.getSearchDate) {
				throw "error options,url can not be null"
			}
			b.options.mouseOnPanel = 0;
			if (!$("#" + b.options.showDivId)[0]) {
				var d = [];
				var c = -1;
				d[++c] = '<div class="station" style="display:none;" id="' + b.options.showDivId + '"><b></b>';
				d[++c] = '<div class="station-info" id="' + b.options.showTitleId + '"></div>';
				d[++c] = '<div class="station-hd"><span class="zx">站序</span><span class="zm">站名</span><span class="dzsj">到站时间</span>';
				d[++c] = '<span class="cfsj">出发时间</span><span class="tlsj">停留时间</span>';
				d[++c] = '<a id="_stopStation_close_id" class="close" title="关闭" href="javascript:" </a></div>';
				d[++c] = '<div class="station-bd"><table><tbody id="' + b.options.showTableId + '"></tbody></table></div></div>';
				$(d.join("")).appendTo($("body:eq(0)"));
				$("#_stopStation_close_id").on("click", b.close)
			}
			$("#" + b.options.showDivId).css("z-index", "20001");
			if (b.options.mouseOutClose) {
				$("#" + b.options.showDivId).on("mouseenter", function(e) {
					b.options.mouseOnPanel = 1
				}).on("mouseleave", function() {
					b.options.mouseOnPanel = 0;
					$("#" + b.options.showDivId).hide().appendTo($("body:eq(0)"));
					$("#" + b.options.showTableId).html("")
				})
			}
		};
		b.close = function() {
			$("#" + $.stopStation.defaultOptions.showDivId).closest("tr").removeAttr("style");
			$("#" + $.stopStation.defaultOptions.showDivId).removeAttr("style");
			b.options.mouseOnPanel = 0;
			$("#" + $.stopStation.defaultOptions.showDivId).hide().appendTo($("body:eq(0)"));
			$("#" + $.stopStation.defaultOptions.showTableId).html("")
		};
		b.open = function(f, j, h, e, i, c) {
			$("#" + $.stopStation.defaultOptions.showDivId).attr("style", "z-index:20001");
			if (a.timer) {
				clearTimeout(a.timer)
			}
			var g = a.getSearchDate();
			if (i && "" != i && null != i) {
				var d = formatDate(i);
				if ("-" != d) {
					g = formatDate(i)
				} else {
					g = a.getSearchDate()
				}
			} else {
				g = a.getSearchDate()
			}
			$.ajax({
				url: a.url,
				type: "get",
				isTakeParam: false,
				beforeSend: function(k) {
					k.setRequestHeader("If-Modified-Since", "0");
					k.setRequestHeader("Cache-Control", "no-cache")
				},
				data: {
					train_no: j,
					from_station_telecode: h,
					to_station_telecode: e,
					depart_date: g
				},
				success: function(p) {
					var t = p.data.data;
					if (t && t.length > 0) {
						var r = [];
						var u = -1;
						for (var q = 0; q < t.length; q++) {
							var l = t[q];
							if (q == 0) {
								var n = null;
								n = l.train_class_name;
								var s = l.service_type;
								if ("0" == s) {
									c = "无空调"
								} else {
									c = "有空调"
								}
								if (!n) {
									n = "&nbsp;&nbsp;"
								}
								$("#" + $.stopStation.defaultOptions.showTitleId).html('<span class="item1">' + l.station_train_code + '次      </span><span class="item2">' + l.start_station_name + "<em>--></em>" + l.end_station_name + '</span><span class="item3">' + n + '</span><span class="item4">' + c + "</span>").find("span").css("color", "#333")
							}
							var m = "";
							if (!l.isEnabled) {
								m = " style='color: #999;' "
							}
							r[++u] = '<tr><td width="50" class="tc" ' + m + ">" + l.station_no + "</td>";
							r[++u] = '<td width="75" ' + m + ">" + l.station_name + "</td>";
							r[++u] = '<td width="75" ' + m + ">" + l.arrive_time + "</td>";
							r[++u] = '<td width="75" ' + m + ">" + l.start_time + "</td>";
							r[++u] = "<td " + m + ">" + l.stopover_time + "</td></tr>"
						}
						$("#" + $.stopStation.defaultOptions.showTableId).html(r.join(""));
						var o = $("#" + $.stopStation.defaultOptions.appendTo + f);
						$("#" + $.stopStation.defaultOptions.showDivId).appendTo(o).show();
						$(".ticket-info").filter("div").attr("style", "");
						o[0].style["z-index"] = 19999;
						if (!(navigator.appVersion.indexOf("MSIE 6") > -1)) {} else {}
					}
				}
			})
		};
		b.init();
		myStopStation = b;
		return b
	};
	$.fn.stopStation = function() {
		return (new $.stopStation(Array.prototype.slice.call(arguments)[0]))
	};
	$.stopStation.defaultOptions = {
		url: null,
		mouseOutClose: false,
		showDivId: "train_div_",
		showTableId: "train_table_",
		showTitleId: "train_span_",
		appendTo: "train_num_",
		getSearchDate: null
	}
})();
var myStopStation = function() {};
var formatDate = function(b) {
	if (b && (b.length == 8)) {
		var c = b.substring(0, 4);
		var d = b.substring(4, 6);
		var a = b.substring(6, 8);
		return c + "-" + d + "-" + a
	} else {
		return "-"
	}
};
var checkusermdId;
var showTrainStop;
var hideTrainStop;
var showTicketPrice;
var isInitQueryInput = false;
var isInitStationDiv = false;
var isInitJsrenderTemplate = false;
var isInitDateRange = false;
var tickets_info;
var location_code;
var md5Str;
var leftTicketStr;
var isAsync;
var box;
var countDown = null;
var ischeckAutoSubmitCode = true;
var hainan_tip;
var firstShow = 1;
var endShow = 20;
var dataNumber = 0;
var change_dates_arr = [];
var isOther = true;
var dwTranTimeStr;
var ydTranTimeStr;
var uninputmsg = "用户名／邮箱／手机号码";
var adtimeout = 5000;
var iframeUrl = "https://ad.12306.cn/res/0004.html";
var frameComplete = false;
var iframeOnload = function() {
	frameComplete = true
};
var yxTrainPageSize = 15;
var passengerPageSize = 20;
var timer_time = 3;
var yxTrainChange = "";
var trainListForIE = [];
var queryLeftTicket_times = 0;
var queryLeftTicket_count = 10;
var ifAlertCode = false;
var intervalTime;
(function() {
	var a;
	var a0 = null;
	var bA;
	var bo;
	var N;
	var af;
	var b9;
	var bR;
	var p = false;
	var bZ = 0;
	var ax;
	var bb;
	var x;
	var ac;
	var cf;
	var a8 = new Array();
	var bO = new Array();
	var bY = new Array();
	var W = new Array();
	var bJ = new Array();
	var K;
	var aC = new Array();
	tickets_info = new Array();
	var a1 = true,
		b1 = true,
		aW = true,
		ay = "starttime";
	var aB = true;
	var bw = [];
	var be = [];
	var bQ = [];
	var aN;
	var H = [];
	var bP = "";
	var b7 = "";
	var a6 = "";
	var g = "";
	var D = "";
	$(document).ready(function() {
		$.init_ul4li();
		f();
		Y();
		y();
		ab();
		F();
		az();
		a3();
		bu();
		clickCheckBoxName();
		bz();
		bT();
		aq();
		ag();
		b3();
		A();
		aV();
		bF();
		$("#float").headerFloat();
		$(window).scroll(function() {
			if (a0 != null && (!a0.isHidden())) {
				$("#floatTable").hide();
				$(window).scrollTop(a)
			}
		});
		$.stopStation({
			url: ctx + "czxx/queryByTrainNo",
			getSearchDate: function() {
				return train_tour_flag == "fc" ? $.trim($("#back_train_date").val()) : $.trim($("#train_date").val())
			}
		});
		ba();
		cj();
		b4();
		o();
		R();
		ad();
		bP = $("#fromStationText").val();
		b7 = $("#toStationText").val();
		$("#showOnlyTicA").bind("click", function() {
			$("#filterTic").attr("checked", "checked");
			bf();
			$jpopup.startOrHiden()
		});
		aN = $.autoSubmit();
		var co = $("#train_date").val();
		var cm = $("#back_train_date").val();
		if (cm == "") {
			$("#back_train_date").val(co)
		} else {
			$("#back_train_date").val(cm)
		}
		t();
		aT();
		var cn = new bn("right");
		cn.init();
		G();
		U();
		if (page_show_flag == "preStep") {
			$("#query_ticket").click()
		}
	});
	var bn = function(ct) {
		var cu, cq = {},
			cv, cr = this,
			cp = false,
			cn, cs, co = {
				x: 10,
				y: 66
			},
			cm = {
				x: 5,
				y: 1
			};
		this.move = function() {
			cn = cn + cm.x;
			cs = cs + cm.y;
			if (cn < co.x) {
				cn = co.x;
				cm.x = -cm.x
			} else {
				if (cn > cq.dx) {
					cn = cq.dx;
					cm.x = -cm.x
				}
			}
			if (cs < co.y) {
				cs = co.y;
				cm.y = -cm.y
			} else {
				if (cs > cq.dy) {
					cs = cq.dy;
					cm.y = -cm.y
				}
			}
			cv.css(ct, cn + "px").css("top", cs + "px")
		};
		this.init = function() {
			if (cp) {
				return
			}
			cp = true;
			cv = $(bn.htmlTemplate);
			$(window).on("resize", cr.resize);
			cv.css(ct, co.x + "px").css({
				top: co.y + "px"
			}).on("mouseenter", cr.stop).on("mouseleave", cr.resize).children("a.close").on("click", cr.hidden);
			$("body").append(cv);
			cn = co.x;
			cs = co.y;
			cr.resize()
		};
		this.destory = function() {
			cv.remove()
		};
		this.resize = function() {
			cq.dx = ($(window).width() - $(".content").width()) / 2 - cv.width();
			cq.dy = ($(window).height()) - cv.height();
			if (cq.dx <= (co.x + Math.abs(cm.x)) || cq.dy <= (co.y + Math.abs(cm.y))) {
				cr.stop()
			} else {
				cr.alive()
			}
		};
		this.show = function() {
			cv.show();
			cr.alive()
		};
		this.hidden = function() {
			cr.stop();
			cv.hide()
		};
		this.stop = function() {
			clearInterval(cu)
		};
		this.alive = function() {
			cr.stop();
			cu = setInterval(cr.move, 200)
		}
	};
	bn.htmlTemplate = '<div class="fix-yh" id="myfix_yh" style="overflow: hidden;"><iframe onload="iframeOnload()" style="border:0;width:110%;height:110%;" id="ad_frame_query" src="' + iframeUrl + '"></iframe></div>';

	function G() {
		setTimeout(function() {
			if (!frameComplete) {
				var cn = $("#ad_frame_query");
				var cm = cn.get(0);
				var co = ctx + "resources/images/bg11.png";
				cn.remove();
				$("#myfix_yh").css("background", "url(" + co + ") no-repeat");
				$("#myfix_yh").html('<a href="javascript:void(0);" class="close" title="关闭">关闭</a>');
				$("#myfix_yh").children("a.close").on("click", function() {
					$(this).parent().hide()
				})
			}
		}, adtimeout)
	}

	function bG(cn) {
		if (cn) {
			$(".yzm").show();
			$("#orange_msg").hide();
			$("#randCodeForm_id").find("a").css("margin-top", "30px");
			var cm = $("#qr_submit1");
			cm.unbind("click").bind("click", h);
			cm.removeClass("btn92").addClass("btn92s").show();
			ifAlertCode = true
		} else {
			$(".yzm").hide();
			$("#orange_msg").show();
			$("#qr_submit1").hide();
			ifAlertCode = false
		}
	}

	function ad() {
		if (rqChecked.length == 0) {
			if (train_tour_flag == "fc") {
				rqChecked.push($("#back_train_date").val())
			} else {
				rqChecked.push($("#train_date").val())
			}
		}
	}

	function b4() {
		if (ClickWho == "0X00") {
			$("#sf1").attr("disabled", "true");
			$("#sf1_label").addClass("color999");
			$("#sf2").attr("checked", "true");
			$("#query_ticket").removeClass().addClass("btn92s")
		} else {
			if (ClickWho == "00" || ClickWho == "ADULT") {
				$("#sf2").attr("disabled", "true");
				$("#sf2_label").addClass("color999");
				$("#query_ticket").removeClass().addClass("btn92s")
			} else {
				$("#query_ticket").removeClass().addClass("btn92s")
			}
		}
		if (isstudentDate) {
			$("#sf2").attr("disabled", "true");
			$("#sf2_label").addClass("color999");
			$("#query_ticket").removeClass().addClass("btn92s")
		}
	}

	function ah() {
		if (!isInitStationDiv) {
			d();
			isInitStationDiv = true
		}
		if (!isInitJsrenderTemplate) {
			at();
			isInitJsrenderTemplate = true
		}
	}

	function ba() {
		$("#fromStationText").mouseover(ah);
		$("#toStationText").mouseover(ah);
		$("#dc").mouseover(ah);
		$("#wf").mouseover(ah);
		$("#dc_label").mouseover(ah);
		$("#wf_label").mouseover(ah);
		$("#train_date").mouseover(ah);
		$("#back_train_date").mouseover(ah);
		$("#date_range").mouseover(ah)
	}

	function aA(cm) {
		aK();
		var ct = bJ.length;
		if ($("#query_ticket").html() == "停止查询") {
			if (ct > 0 && aO) {
				$("#auto_query").removeAttr("disabled");
				if ($("#dc").is(":checked") && train_tour_flag != "gc") {
					$("#autoSubmit").removeAttr("disabled");
					$("#partSubmit").removeAttr("disabled")
				}
				$("#query_ticket").html("查询");
				$("#query_ticket").unbind("click");
				bK();
				if (countDown) {
					clearInterval(countDown)
				}
				$("#filterTicDiv").html("<strong><label for='filterTic' style='cursor: pointer;'>仅显示选定车次</label></strong>");
				if (!$("#autoSubmit").is(":checked")) {
					clearInterval(aY);
					if (ccSelected.length > 0 || rqChecked.length > 0 || xbChecked.length > 0) {
						myJpopup.startOrHiden();
						if (train_tour_flag == "fc") {
							var cu = "成功查到" + $("#back_train_date").val() + "的" + bJ[0]["queryLeftNewDTO"]["station_train_code"] + "次"
						} else {
							var cu = "成功查到" + $("#train_date").val() + "的" + bJ[0]["queryLeftNewDTO"]["station_train_code"] + "次"
						}
						if (ct == 1) {
							cu = cu + "车。"
						} else {
							cu = cu + "等" + ct + "趟车。"
						}
						$("#filterRes").html(cu)
					}
				}
				jPlayer("play")
			} else {
				if (countDown) {
					clearInterval(countDown)
				}
				var cs = autoSearchTime / 1000;
				$("#filterTicDiv").html("<strong>离下次刷新时间<font class='colorA' style='font-size: 16px;'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" + cs + "</font>秒<strong>");
				countDown = window.setInterval(function() {
					var cv = "<strong>离下次刷新时间<font class='colorA' style='font-size: 16px;'>";
					if (cs == 0) {
						cs = autoSearchTime / 1000
					}
					cs = cs - 1;
					if (cs == 4) {
						cv = cv + "&nbsp;&nbsp;&nbsp;&nbsp;"
					}
					if (cs == 3) {
						cv = cv + "&nbsp;&nbsp;&nbsp;"
					}
					if (cs == 2) {
						cv = cv + "&nbsp;&nbsp;"
					}
					if (cs == 1) {
						cv = cv + "&nbsp;"
					}
					cv = cv + cs;
					cv += "</font>秒<strong>";
					$("#filterTicDiv").html(cv)
				}, 1000);
				$("#filterTic").hide()
			}
		}
		var cr = new Array();
		cr.push('<tbody id="queryLeftTable">');
		var co = bV(cm);
		if (co) {
			cm = cb(cm)
		}
		for (var cn = 0; cn < cm.length; cn++) {
			cr.push('<tr id="ticket_');
			cr.push(cm[cn].queryLeftNewDTO.train_no);
			cr.push('" class="');
			cr.push(cn % 2 ? '">' : 'bgc">');
			cr.push('<td colspan="4" width="370">');
			cr.push('<div class="ticket-info clearfix" id="train_num_');
			cr.push(cn);
			cr.push('">');
			cr.push('<div class="train" id="ticket_');
			cr.push(cm[cn].queryLeftNewDTO.train_no);
			cr.push('_train">');
			var cq = "";
			if (c(cm[cn].queryLeftNewDTO.station_train_code)) {
				cq = ' style="color:red;" '
			}
			cr.push("<div><a  " + cq + ' title="点击查看停靠站信息" href="javascript:" id="');
			cr.push(cm[cn].queryLeftNewDTO.train_no);
			cr.push("_");
			cr.push(cm[cn].queryLeftNewDTO.from_station_telecode);
			cr.push("_");
			cr.push(cm[cn].queryLeftNewDTO.to_station_telecode);
			if ("1" == cm[cn].queryLeftNewDTO.controlled_train_flag || "2" == cm[cn].queryLeftNewDTO.controlled_train_flag) {
				cr.push('" class="number"');
				cr.push(">")
			} else {
				cr.push('" class="number"  onclick="myStopStation.open(\'');
				cr.push(cn);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.train_no);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.from_station_telecode);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.to_station_telecode);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.start_train_date);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.train_seat_feature);
				cr.push("');\">")
			}
			cr.push(cm[cn].queryLeftNewDTO.station_train_code);
			cr.push("</a>");
			if (cm[cn].queryLeftNewDTO.is_support_card != 0) {
				cr.push(' <span class="i-card" title="可凭二代身份证直接进出站"></span>')
			}
			cr.push("</div>");
			cr.push('<span id="');
			cr.push(cm[cn].queryLeftNewDTO.train_no);
			cr.push("_");
			cr.push(cm[cn].queryLeftNewDTO.from_station_no);
			cr.push("_");
			cr.push(cm[cn].queryLeftNewDTO.to_station_no);
			cr.push("_");
			cr.push(cm[cn].queryLeftNewDTO.yp_info);
			cr.push("_");
			cr.push(cm[cn].queryLeftNewDTO.seat_types);
			if ("1" == cm[cn].queryLeftNewDTO.controlled_train_flag || "2" == cm[cn].queryLeftNewDTO.controlled_train_flag) {
				cr.push('" class="lookup"><span style="display:none;">查看票价</span><b style="display:none;" title="查看票价"></b></span>')
			} else {
				cr.push('" class="lookup" onclick="showTicketPrice(this)"><span style="display:none;">查看票价</span><b title="查看票价"></b></span>')
			}
			cr.push("</div>");
			cr.push('<div class="cdz">');
			if (cm[cn].queryLeftNewDTO.from_station_telecode != null && cm[cn].queryLeftNewDTO.from_station_telecode == cm[cn].queryLeftNewDTO.start_station_telecode) {
				cr.push('<strong class="start-s">');
				cr.push(cm[cn].queryLeftNewDTO.from_station_name);
				cr.push("</strong>")
			} else {
				cr.push("<strong>");
				cr.push(cm[cn].queryLeftNewDTO.from_station_name);
				cr.push("</strong>")
			}
			if (cm[cn].queryLeftNewDTO.to_station_telecode != null && cm[cn].queryLeftNewDTO.to_station_telecode == cm[cn].queryLeftNewDTO.end_station_telecode) {
				cr.push('<strong class="end-s">');
				cr.push(cm[cn].queryLeftNewDTO.to_station_name);
				cr.push("</strong>")
			} else {
				cr.push("<strong>");
				cr.push(cm[cn].queryLeftNewDTO.to_station_name);
				cr.push("</strong>")
			}
			cr.push("</div>");
			cr.push('<div class="cds">');
			if ("1" == cm[cn].queryLeftNewDTO.controlled_train_flag || "2" == cm[cn].queryLeftNewDTO.controlled_train_flag) {
				cr.push('<strong class="start-t" style="color:#999;">');
				cr.push("-----");
				cr.push("</strong>");
				cr.push('<strong class="color999">');
				cr.push("-----");
				cr.push("</strong>")
			} else {
				cr.push('<strong class="start-t">');
				cr.push(cm[cn].queryLeftNewDTO.start_time);
				cr.push("</strong>");
				cr.push('<strong class="color999">');
				cr.push(cm[cn].queryLeftNewDTO.arrive_time);
				cr.push("</strong>")
			}
			cr.push("</div>");
			cr.push('<div  class="ls" ');
			cr.push('id="');
			cr.push(cm[cn].queryLeftNewDTO.train_no);
			cr.push('_ls">');
			if ("1" == cm[cn].queryLeftNewDTO.controlled_train_flag || "2" == cm[cn].queryLeftNewDTO.controlled_train_flag) {
				cr.push('<strong class="color999">');
				cr.push("------");
				cr.push("</strong>");
				cr.push('<strong class="color999">');
				cr.push("------");
				cr.push("</strong>")
			} else {
				cr.push("<strong>");
				cr.push(cm[cn].queryLeftNewDTO.lishi);
				cr.push("</strong>");
				cr.push("<span>");
				cr.push(changeArriveDate(cm[cn].queryLeftNewDTO.start_time, cm[cn].queryLeftNewDTO.lishi));
				cr.push("到达</span>")
			}
			cr.push("</div>");
			cr.push("</div>");
			cr.push("</td>");
			if (cm[cn].queryLeftNewDTO.swz_num && cm[cn].queryLeftNewDTO.swz_num != "--" && cm[cn].queryLeftNewDTO.swz_num != 0 && cm[cn].queryLeftNewDTO.swz_num != "无") {
				b5(cr, cm[cn].queryLeftNewDTO.swz_num, "SWZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "91", cm[cn].queryLeftNewDTO.controlled_train_flag)
			} else {
				if (cm[cn].queryLeftNewDTO.tz_num && cm[cn].queryLeftNewDTO.tz_num != "--" && cm[cn].queryLeftNewDTO.tz_num != 0 && cm[cn].queryLeftNewDTO.tz_num != "无") {
					b5(cr, cm[cn].queryLeftNewDTO.tz_num, "TZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "P1", cm[cn].queryLeftNewDTO.controlled_train_flag)
				} else {
					if (cm[cn].queryLeftNewDTO.swz_num && cm[cn].queryLeftNewDTO.swz_num == "无") {
						b5(cr, cm[cn].queryLeftNewDTO.swz_num, "SWZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "91", cm[cn].queryLeftNewDTO.controlled_train_flag)
					} else {
						b5(cr, cm[cn].queryLeftNewDTO.tz_num, "TZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "P1", cm[cn].queryLeftNewDTO.controlled_train_flag)
					}
				}
			}
			b5(cr, cm[cn].queryLeftNewDTO.zy_num, "ZY_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "M1", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.ze_num, "ZE_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "O1", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.gr_num, "GR_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "61", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.rw_num, "RW_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "41", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.srrb_num, "SRRB_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "F1", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.yw_num, "YW_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "31", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.rz_num, "RZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "21", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.yz_num, "YZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "11", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.wz_num, "WZ_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "W1", cm[cn].queryLeftNewDTO.controlled_train_flag);
			b5(cr, cm[cn].queryLeftNewDTO.qt_num, "QT_", cm[cn].queryLeftNewDTO.train_no, cm[cn].queryLeftNewDTO.yp_ex, "", cm[cn].queryLeftNewDTO.controlled_train_flag);
			if ("Y" == cm[cn].queryLeftNewDTO.canWebBuy) {
				cr.push(' <td align="center" width="80" class="no-br"><a href="javascript:" class="btn72" onclick="checkG1234(\'');
				cr.push(cm[cn].secretStr);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.start_time);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.train_no);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.from_station_telecode);
				cr.push("','");
				cr.push(cm[cn].queryLeftNewDTO.to_station_telecode);
				cr.push("')\">");
				cr.push(buttonText());
				cr.push("</a>");
				cr.push("</td>")
			} else {
				cr.push('<td align="center" width="80" class="no-br">');
				cr.push(cm[cn].buttonTextInfo);
				cr.push("</td>")
			}
			cr.push("</tr>");
			cr.push('<tr datatran="' + cm[cn].queryLeftNewDTO.station_train_code + '" id="price_');
			cr.push(cm[cn].queryLeftNewDTO.train_no);
			cr.push('" style="display:none;"></tr>')
		}
		cr.push("</tbody>");
		$("#queryLeftTable").replaceWith(cr.join(""));
		if (co) {
			for (var cn = 0; cn < cm.length; cn++) {
				var cp = cm[cn];
				if (c(cp.queryLeftNewDTO.station_train_code)) {}
			}
		}
	}

	function cb(cn) {
		if (cn && cn.length > 0) {
			var cr = [];
			var cm = [];
			for (var co = 0, cp = cn.length; co < cp; co++) {
				var cq = cn[co];
				if (c(cq.queryLeftNewDTO.station_train_code)) {
					cr.push(cq)
				} else {
					cm.push(cq)
				}
			}
			cn = cr.concat(cm)
		}
		return cn
	}

	function c(co) {
		if (DW_TRAINS && DW_TRAINS.length) {
			for (var cm = 0, cn = DW_TRAINS.length; cm < cn; cm++) {
				if (co == DW_TRAINS[cm]) {
					return true
				}
			}
		} else {
			return false
		}
		return false
	}

	function bV(cm) {
		if (cm && cm.length > 0) {
			if (DW_TRAINS && DW_TRAINS.length) {
				for (var cp = 0, cr = cm.length; cp < cr; cp++) {
					var cq = cm[cp].queryLeftNewDTO.station_train_code;
					for (var cn = 0, co = DW_TRAINS.length; cn < co; cn++) {
						if (cq == DW_TRAINS[cn]) {
							return true
						}
					}
				}
			}
		}
		return false
	}

	function ae(cs, cm) {
		var ct, cq, cp;
		var co;
		cp = cs["leftTicketDTO.train_date"];
		if (hainan_limit_start_traindate && C(cp) >= C(hainan_limit_start_traindate)) {
			if (hainan_limit_from_telcode && hainan_limit_to_telcode) {
				for (var cn = 0, cr = cm.length; cn < cr; cn++) {
					ct = cm[cn].queryLeftNewDTO.from_station_telecode;
					cq = cm[cn].queryLeftNewDTO.to_station_telecode;
					co = cm[cn].buttonTextInfo;
					if (hainan_limit_from_telcode.indexOf(ct) > -1 && hainan_limit_to_telcode.indexOf(cq) > -1 && co.indexOf("起售") > -1) {
						return true
					}
				}
			}
		}
		return false
	}

	function b5(cq, cn, cv, cr, co, cu, cp) {
		co = co.replace("F", "4").replace("A", "6");
		var ct = co ? co.indexOf(cu) : -1;
		var cs = false;
		if (ct > -1 && (ct % 2) == 0) {
			cs = true
		}
		if ("1" == cp || "2" == cp) {
			cq.push(' <td width="46" align="center" style="cursor: pointer;"  id="');
			cq.push(cv);
			cq.push(cr);
			cq.push('">');
			cq.push(cn);
			cq.push("</td>")
		} else {
			if ("有" == cn) {
				if (cv == "SWZ_" || cv == "TZ_") {
					cq.push('<td width="46" align="center" class="yes" onclick="showTicketPrice(this)"　style="cursor: pointer;" id="');
					cq.push(cv);
					cq.push(cr);
					cq.push('">');
					if (cs) {
						cq.push('<div class="sale" title="本席别票价打折">' + cn + '<span class="i-mark">折</span></div>')
					} else {
						cq.push(cn)
					}
					cq.push("</td>")
				} else {
					if (cv == "ZY_" || cv == "ZE_") {
						cq.push('<td width="46" align="center" class="yes" style="cursor: pointer;" onclick="showTicketPrice(this)" id="');
						cq.push(cv);
						cq.push(cr);
						cq.push('">');
						if (cs) {
							cq.push('<div class="sale" title="本席别票价打折">' + cn + '<span class="i-mark">折</span></div>')
						} else {
							cq.push(cn)
						}
						cq.push("</td>")
					} else {
						cq.push('<td width="46" align="center" style="cursor: pointer;" class="yes" onclick="showTicketPrice(this)" id="');
						cq.push(cv);
						cq.push(cr);
						cq.push('">');
						if (cs) {
							cq.push('<div class="sale" title="本席别票价打折">' + cn + '<span class="i-mark">折</span></div>')
						} else {
							cq.push(cn)
						}
						cq.push("</td>")
					}
				}
			} else {
				if (cn == "无" || isNum(cn) >= 0) {
					var cm = ' class="t-num" ';
					if (cn == "无" || isNum(cn) == 0) {
						cm = ""
					}
					if (cv == "SWZ_" || cv == "TZ_" || cv == "ZY_" || cv == "ZE_") {
						cq.push('<td width="46" align="center" style="cursor: pointer;" ' + cm + ' onclick="showTicketPrice(this)" id="');
						cq.push(cv);
						cq.push(cr);
						cq.push('">');
						cq.push("<div>");
						if (cs) {
							cq.push('<div class="sale" title="本席别票价打折">' + cn + '<span class="i-mark">折</span></div>')
						} else {
							cq.push(cn)
						}
						cq.push("</td>")
					} else {
						cq.push('<td width="46" align="center" style="cursor: pointer;" ' + cm + ' onclick="showTicketPrice(this)" id="');
						cq.push(cv);
						cq.push(cr);
						cq.push('">');
						if (cs) {
							cq.push('<div class="sale" title="本席别票价打折">' + cn + '<span class="i-mark">折</span></div>')
						} else {
							cq.push(cn)
						}
						cq.push("</td>")
					}
				} else {
					cq.push(' <td width="46" align="center" style="cursor: pointer;" onclick="showTicketPrice(this)"  id="');
					cq.push(cv);
					cq.push(cr);
					cq.push('">');
					cq.push(cn);
					cq.push("</td>")
				}
			}
		}
	}

	function k(cn, cm) {
		ishaveCheckId = false;
		for (i = 0; i < cn.length; i++) {
			if (cn[i][0] == cm) {
				cn[i][1] = $("#".concat($("#".concat(cm)).attr("for"))).is(":checked");
				ishaveCheckId = true
			}
		}
		if (!ishaveCheckId) {
			cn[cn.length] = [cm, true]
		}
	}

	function bM() {
		e(bA);
		e(bo);
		e(N)
	}

	function e(cm) {
		for (i = 0; i < cm.length; i++) {
			if (cm[i][1]) {
				$("#".concat(cm[i][0]).concat("_check")).attr("checked", true)
			}
		}
	}

	function C(cn) {
		var cm = new Date();
		var co = cn.split("-");
		cm.setFullYear(parseInt(co[0]), parseInt(co[1] - 1, 10), parseInt(co[2], 10));
		if (co.length >= 6) {
			cm.setHours(co[3], co[4], co[5])
		}
		return cm
	}
	Date.prototype.format = function(cn) {
		var co = {
			"M+": this.getMonth() + 1,
			"d+": this.getDate(),
			"h+": this.getHours(),
			"m+": this.getMinutes(),
			"s+": this.getSeconds(),
			"q+": Math.floor((this.getMonth() + 3) / 3),
			S: this.getMilliseconds()
		};
		if (/(y+)/.test(cn)) {
			cn = cn.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length))
		}
		for (var cm in co) {
			if (new RegExp("(" + cm + ")").test(cn)) {
				cn = cn.replace(RegExp.$1, RegExp.$1.length == 1 ? co[cm] : ("00" + co[cm]).substr(("" + co[cm]).length))
			}
		}
		return cn
	};

	function aJ(co, cn) {
		var cm = new Date(Date.parse(co.replace(/-/g, "/")));
		cm.setDate(cm.getDate() + cn);
		return P(cm)
	}

	function P(cn) {
		var co = cn.getFullYear();
		var cq = cn.getMonth() + 1;
		var cp = cn.getDate();
		var cm = co + "-" + cq + "-" + cp;
		return cm
	}

	function bC() {
		var co = $("#train_date").val();
		var cn = $("#back_train_date").val();
		var cm = false;
		if ($("#wf").is(":checked")) {
			if (C(co) <= C(cn)) {
				cm = true
			}
		} else {
			return true
		}
		return cm
	}

	function cd() {
		var cp = $.jc_getFromStation();
		if (cp) {
			var co = cp.split(",");
			if (co && co.length == 2) {
				$("#fromStationText").val(co[0]);
				$("#fromStation").val(co[1])
			}
		}
		var cn = $.jc_getToStation();
		if (cn) {
			var co = cn.split(",");
			if (co && co.length == 2) {
				$("#toStationText").val(co[0]);
				$("#toStation").val(co[1])
			}
		}
		var cq = [];
		cq = stu_buy_date.split("&");
		var cm = $.jc_getFromDate();
		if (cm) {
			if (cm >= cq[0] && cm <= cq[1]) {
				$("#train_date").val(cm)
			}
		}
		var cr = $.jc_getWfOrDc();
		if (cr && "wf" == cr) {
			$("#wf").click();
			var cs = $.jc_getToDate();
			if (cs) {
				if (cs >= cq[0] && cs <= cq[1]) {
					$("#back_train_date").val(cs)
				}
			}
		} else {
			$("#dc").click()
		}
	}

	function aZ() {
		$("#train_stop").on("mouseover", function(cm) {
			if (checkHover(cm, this)) {
				bZ = 1
			}
		}).on("mouseleave", function() {
			bZ = 0;
			$("#train_stop").hide();
			$("#train_table_").html("")
		})
	}

	function f() {
		fromStation = from_station;
		fromStationName = from_station_name;
		toStation = to_station;
		toStationName = to_station_name;
		trainDate = trainDate;
		backTrainDate = backTrainDate;
		bA = new Array();
		bo = new Array();
		N = new Array()
	}

	function t() {
		if ($("#sf1").is(":checked")) {
			isOther = true;
			if (other_control < dataNumber) {
				for (var cm = other_control + 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").hide()
				}
			} else {
				for (var cm = 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").show()
				}
			}
		} else {
			isOther = false;
			if (stu_control < dataNumber) {
				for (var cm = stu_control + 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").hide()
				}
			} else {
				for (var cm = 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").show()
				}
			}
		}
	}

	function o() {
		$("#fromStation").val(fromStation);
		$("#fromStationText").val(fromStationName);
		$("#toStation").val(toStation);
		$("#toStationText").val(toStationName);
		$("#train_date").val(trainDate);
		if (isInMaintenanceHours) {
			if (!isSuperLogin) {
				$("#autoSubmit").prop("checked", false);
				$("#autoSubmit").attr("disabled", true);
				$("#autoSubmit").siblings("label").css("color", "#999");
				$("#autoSubmitTxt").attr("title", "系统维护时间下不允许自动提交");
				$("#partSubmit").prop("checked", false);
				$("#partSubmit").attr("disabled", true);
				$("#partSubmit").siblings("label").css("color", "#999");
				$("#partSubmitTxt").attr("title", "系统维护时间下不允许自动提交");
				$("#auto_query").prop("checked", false);
				$("#auto_query").attr("disabled", true);
				$("#auto_query").siblings("label").css("color", "#999");
				$("#autoQueryTxt").attr("title", "系统维护时间下不允许自动查询")
			}
		}
		if (backTrainDate != null && backTrainDate != "") {
			$("#back_train_date").val(backTrainDate)
		}
		if ($("#fromStationText").val() == "") {
			$("#fromStationText").val("简拼/全拼/汉字")
		}
		if ($("#toStationText").val() == "") {
			$("#toStationText").val("简拼/全拼/汉字")
		}
		if (page_show_flag == null) {
			cd()
		} else {
			if (page_show_flag == "index") {
				bm()
			} else {
				if (page_show_flag == "preStep") {
					b8()
				} else {
					if (page_show_flag == "fcInit") {
						v();
						$("#autoSubmit").attr("disabled", true);
						$("#autoSubmit").siblings("label").css("color", "#999");
						$("#partSubmit").attr("disabled", true);
						$("#partSubmit").siblings("label").css("color", "#999")
					} else {
						if (page_show_flag == "gcInit") {
							bp();
							$("#autoSubmit").attr("disabled", true);
							$("#autoSubmit").siblings("label").css("color", "#999");
							$("#partSubmit").attr("disabled", true);
							$("#partSubmit").siblings("label").css("color", "#999")
						}
					}
				}
			}
		}
	}

	function bm() {
		if (tour_flag == "wf") {
			$("#wf").click()
		} else {
			if (tour_flag == "dc") {
				$("#dc").click()
			}
		}
		if (purposeCodeFromIndex == "0X00") {
			$("#sf2").click()
		} else {
			if (purposeCodeFromIndex == "ADULT") {
				$("#sf1").click()
			}
		}
		var cm = [];
		$("#date_range>ul>li").each(function() {
			var cn = $(this).children("span:first-child").html();
			cm.push(cn)
		});
		$("#query_ticket").click()
	}

	function b8() {
		$("#fromStationText").removeClass().addClass("inp_selected");
		$("#toStationText").removeClass().addClass("inp_selected");
		if (train_tour_flag == "dc") {
			ar(trainDate);
			$("#dc").click()
		}
		if (train_tour_flag == "wc") {
			ar(trainDate);
			$("#wf").click()
		}
		if (train_tour_flag == "fc") {
			ar(backTrainDate);
			$("#wf").click();
			$("#wf").attr("disabled", "true");
			$("#dc").attr("disabled", "true");
			$("#change_station").removeClass().addClass("i-change i-change2");
			$("#change_station").attr("style", "");
			$("#fromStationText").attr("title", "返程时不得变更出发地或不能变更到达地");
			$("#toStationText").attr("title", "返程时不得变更出发地或不能变更到达地");
			$("#toStationText").unbind("focus").unbind("click").attr("readonly", "true");
			$("#fromStationText").unbind("focus").unbind("click").attr("readonly", "true");
			$("#dfc>ul>li:nth-child(2)").children("label:first").removeClass().addClass("color999");
			$("#dfc>ul>li:nth-child(1)").children("label:first").removeClass().addClass("color999");
			$("#place_area>ul>li:nth-child(1)").addClass("no-change");
			$("#place_area>ul>li:nth-child(3)").addClass("no-change");
			$("#place_area>ul>li:nth-child(4)").addClass("no-change");
			$("#fromStationText").removeClass().addClass("inp-txt");
			$("#toStationText").removeClass().addClass("inp-txt");
			$("#change_station").unbind();
			$("#train_date").val(trainDate);
			$("#train_date").attr("readonly", "true");
			$("#train_date").removeClass().addClass("inp-txt");
			$("#train_date").unbind("click");
			$("#date_icon_1").unbind("click");
			$("#date_area>ul>li:nth-child(1)>span>label").addClass("color999");
			$("#back_train_date").val(backTrainDate);
			$("#back_train_date").removeAttr("disabled");
			$("#date_area>ul>li:nth-child(2)>span>label").removeClass("color999");
			$("#back_train_date").removeClass().addClass("inp_selected");
			$("#autoSubmit").attr("disabled", true);
			$("#autoSubmit").siblings("label").css("color", "#999");
			$("#partSubmit").attr("disabled", true);
			$("#partSubmit").siblings("label").css("color", "#999")
		}
		if (train_tour_flag == "gc") {
			ar(trainDate);
			bp();
			$("#autoSubmit").attr("disabled", true);
			$("#autoSubmit").siblings("label").css("color", "#999");
			$("#partSubmit").attr("disabled", true);
			$("#partSubmit").siblings("label").css("color", "#999")
		}
	}

	function ar(co) {
		for (var cm = 1; cm <= 20; cm++) {
			var cn = $("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").text();
			cn = "2013-" + cn;
			if (co == cn) {
				$("#date_range>ul>li").removeClass("sel");
				$("#date_range>ul>li").removeAttr("alt");
				$("#date_range>ul>li:nth-child(" + cm + ")").addClass("sel");
				$("#date_range>ul>li:nth-child(" + cm + ")").attr("alt", "show");
				$("#date_range>ul>li:nth-child(20)").addClass("end");
				$("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").removeClass();
				$("#date_range>ul>li:nth-child(" + cm + ")").children("span:last-child").removeClass();
				$("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").addClass("hide");
				$("#date_range>ul>li:nth-child(1)").children().addClass("first");
				bR = $("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").text();
				break
			}
		}
	}

	function bp() {
		$("#fromStationText").attr("title", "改签时不得变更出发地或不能变更到达地");
		$("#dc").click();
		$("#wf").attr("disabled", "true");
		$("#dc").attr("disabled", "true");
		$("#place_area>ul>li:nth-child(1)").addClass("no-change");
		$("#place_area>ul>li:nth-child(3)").addClass("no-change");
		$("#place_area>ul>li:nth-child(5)").addClass("no-change");
		$("#dfc>ul>li:nth-child(1)").children("label:first").removeClass().addClass("color999");
		$("#dfc>ul>li:nth-child(2)").children("label:first").removeClass().addClass("color999");
		$("#fromStationText").unbind("focus").unbind("click").attr("readonly", "true");
		if ("Y" != canChangeToStation) {
			$("#toStationText").unbind("focus").unbind("click").attr("readonly", "true");
			$("#toStationText").removeClass().addClass("inp-txt");
			$("#toStationText_label").addClass("color999")
		}
		$("#fromStationText").removeClass().addClass("inp-txt");
		$("#fromStationText_label").addClass("color999");
		$("#change_station").unbind();
		$("#change_station").removeClass().addClass("i-change i-change2");
		$("#change_station").attr("style", "")
	}

	function v() {
		$("#fromStationText").attr("title", "订返程票时不得变更出发地或不能变更到达地");
		$("#toStationText").attr("title", "订返程票时不得变更出发地或不能变更到达地");
		ar(backTrainDate);
		$("#wf").click();
		$("#dc").attr("disabled", "true");
		$("#wf").attr("disabled", "true");
		$("#place_area>ul>li:nth-child(1)").addClass("no-change");
		$("#place_area>ul>li:nth-child(3)").addClass("no-change");
		$("#place_area>ul>li:nth-child(4)").addClass("no-change");
		$("#dfc>ul>li:nth-child(1)").children("label:first").removeClass().addClass("color999");
		$("#dfc>ul>li:nth-child(2)").children("label:first").removeClass().addClass("color999");
		$("#train_date").attr("readonly", "true");
		$("#train_date").addClass("color999");
		$("#train_date").attr("disabled", true);
		$("#train_date").unbind("click");
		$("#date_icon_1").unbind("click");
		$("#date_area>ul>li:nth-child(1)>span>label").addClass("color999");
		$("#back_train_date").removeAttr("disabled");
		$("#date_area>ul>li:nth-child(2)>span>label").removeClass("color999");
		$("#train_date").removeClass().addClass("inp-txt");
		$("#back_train_date").removeClass().addClass("inp_selected");
		$("#fromStationText").unbind("focus").unbind("unfocus").unbind("click").attr("readonly", "true");
		$("#toStationText").unbind("focus").unbind("unfocus").unbind("click").attr("readonly", "true");
		$("#fromStationText").removeClass().addClass("inp-txt");
		$("#toStationText").removeClass().addClass("inp-txt");
		$("#change_station").unbind();
		$("#change_station").removeClass().addClass("i-change i-change2");
		$("#change_station").attr("style", "")
	}

	function Y() {
		initPageTitle(1);
		$("#train_type_btn_all").css("cursor", "pointer");
		$("#start_time_btn_all").css("cursor", "pointer");
		$("#arrive_time_btn_all").css("cursor", "pointer");
		$("#seat_type_btn_all").css("cursor", "pointer");
		$("#from_station_name_all").css("cursor", "pointer");
		$("#to_station_name_all").css("cursor", "pointer");
		$("#change_station").css("cursor", "pointer");
		$("#show_more").css("cursor", "pointer");
		$("#date_normal").css("cursor", "pointer");
		$("#lookup").css("cursor", "pointer");
		$("#s_time").css("cursor", "pointer");
		$("#r_time").css("cursor", "pointer");
		$("#l_s").css("cursor", "pointer");
		$("#other_span_starttime").css("cursor", "pointer");
		$("#other_span_endtime").css("cursor", "pointer");
		$("#other_span_lishi").css("cursor", "pointer");
		$("#date_range>ul>li").children("span:nth-child(1)").css("cursor", "pointer");
		$("#cc_seat_type_btn_all>ul>li").hide();
		$("#train_date").removeClass().addClass("inp_selected");
		if ($("#fromStationText").val() != "" && $("#fromStationText").val() != "简拼/全拼/汉字" || $("#toStationText").val() != "" && $("#toStationText").val() != "简拼/全拼/汉字") {
			$("#fromStationText").removeClass().addClass("inp_selected");
			$("#toStationText").removeClass().addClass("inp_selected")
		}
		var cm = stu_start_train_date.split("&");
		var cn = stu_end_tain_date.split("&")
	}

	function ca(cn) {
		var cm = ("00" + (cn.getMonth() + 1)).slice(-2) + "-";
		cm += ("00" + cn.getDate()).slice(-2) + " 00:00:00";
		return cm
	}

	function y() {
		$("#dc").click(function() {
			$("#wf").attr("checked", false);
			$("#dc").attr("checked", "true");
			$("#place_area>ul>li:nth-child(5)").addClass("no-change");
			$("#back_train_date").removeClass().addClass("inp-txt");
			$("#back_train_date").attr("disabled", true)
		});
		$("#wf").click(function() {
			$("#dc").attr("checked", false);
			$("#wf").attr("checked", true);
			$("#back_train_date").removeAttr("disabled");
			$("#place_area>ul>li:nth-child(5)").removeClass();
			$("#train_date").removeClass().addClass("inp_selected");
			$("#back_train_date").removeClass().addClass("inp_selected");
			isbigdate = bC();
			if (!isbigdate) {
				train = $("#train_date").val();
				$("#back_train_date").val(train)
			}
			var cm = $("#train_date").val()
		})
	}

	function a3() {
		$("#avail_ticket").click(function() {
			$("#filterTic").attr("checked", false);
			aH()
		});
		$("#train_type_btn_all").click(function() {
			var cm = true;
			$("#sear-sel-bd input[name='cc_type']").each(function() {
				if (!this.checked) {
					cm = false
				}
			});
			if (cm) {
				$("#sear-sel-bd input[name='cc_type']").each(function() {
					this.checked = false
				});
				$("#train_type_btn_all").removeClass().addClass("btn-all")
			} else {
				$("#sear-sel-bd input[name='cc_type']").each(function() {
					if (!this.checked) {
						this.checked = true
					}
				});
				$("#train_type_btn_all").removeClass().addClass("btn-all")
			}
			aH()
		});
		$("#start_time_btn_all").click(function() {
			var cm = true;
			$("#sear-sel-bd input[name='cc_start_time']").each(function() {
				if (!this.checked) {
					cm = false
				}
			});
			if (cm) {
				$("#sear-sel-bd input[name='cc_start_time']").each(function() {
					this.checked = false
				});
				$("#start_time_btn_all").removeClass().addClass("btn-all")
			} else {
				$("#sear-sel-bd input[name='cc_start_time']").each(function() {
					if (!this.checked) {
						this.checked = true
					}
				});
				$("#start_time_btn_all").removeClass().addClass("btn-all")
			}
			aH()
		});
		$("#from_station_name_all").click(function() {
			var cm = true;
			$("#sear-sel-bd input[name='cc_from_station']").each(function() {
				if (!this.checked) {
					cm = false
				}
			});
			if (cm) {
				$("#sear-sel-bd input[name='cc_from_station']").each(function() {
					this.checked = false;
					k(bA, "cc_from_station_" + $(this).val())
				});
				$("#from_station_name_all").removeClass().addClass("btn-all")
			} else {
				$("#sear-sel-bd input[name='cc_from_station']").each(function() {
					if (!this.checked) {
						this.checked = true;
						k(bA, "cc_from_station_" + $(this).val())
					}
				});
				$("#from_station_name_all").removeClass().addClass("btn-all")
			}
			aH()
		});
		$("#to_station_name_all").click(function() {
			var cm = true;
			$("#sear-sel-bd input[name='cc_to_station']").each(function() {
				if (!this.checked) {
					cm = false
				}
			});
			if (cm) {
				$("#sear-sel-bd input[name='cc_to_station']").each(function() {
					this.checked = false;
					k(bo, "cc_to_station_" + $(this).val())
				});
				$("#to_station_name_all").removeClass().addClass("btn-all")
			} else {
				$("#sear-sel-bd input[name='cc_to_station']").each(function() {
					if (!this.checked) {
						this.checked = true;
						k(bo, "cc_to_station_" + $(this).val())
					}
				});
				$("#to_station_name_all").removeClass().addClass("btn-all")
			}
			aH()
		})
	}

	function bT() {
		$("#change_station").bind("click", function() {
			var cq = $("#fromStationText").val();
			var cs = $("#fromStation").val();
			var cr = $("#toStationText").val();
			var cm = $("#toStation").val();
			if ((cq != "" && cq != "简拼/全拼/汉字") && (cr != "" && cr != "简拼/全拼/汉字")) {
				$("#fromStationText").val(cr);
				$("#toStationText").val(cq);
				$("#fromStation").val(cm);
				$("#toStation").val(cs);
				$("#fromStationText").removeClass().addClass("inp_selected");
				$("#toStationText").removeClass().addClass("inp_selected")
			} else {
				bb.checkForm();
				bb.hideErrors();
				var cp = bb.errorList;
				for (var co = 0; co < cp.length; co++) {
					var cn = cp[co];
					$(cn.element).next().addClass("error")
				}
				bb.checkForm()
			}
			bL()
		})
	}

	function bL() {
		if ($("#fromStationText").val() == "简拼/全拼/汉字") {
			$.stationFor12306.from_to_station_class_gray($("#fromStationText"))
		} else {
			$.stationFor12306.from_to_station_class_plain($("#fromStationText"))
		}
		if ($("#toStationText").val() == "简拼/全拼/汉字") {
			$.stationFor12306.from_to_station_class_gray($("#toStationText"))
		} else {
			$.stationFor12306.from_to_station_class_plain($("#toStationText"))
		}
	}

	function bz() {
		$("#show_more").click(function() {
			var cm = $(this);
			if (cm.hasClass("down")) {
				au();
				cm.attr("class", "up")
			} else {
				document.getElementById("sear-sel-bd").style.height = "17px";
				cm.attr("class", "down");
				cm.parent().css("top", "58px")
			}
		})
	}

	function n() {
		if ($("#show_more").hasClass("up")) {
			au()
		}
	}

	function au() {
		var co = "17px";
		var cq = 179;
		var cp = 28;
		var cm = $("#sear-sel-bd input[name='cc_from_station']").length;
		var cr = $("#sear-sel-bd input[name='cc_to_station']").length;
		var cn = $("#sear-sel-bd input[name='cc_seat_type']").length;
		if (cm > 7 && cm <= 14) {
			co = (cq + cp) + "px"
		} else {
			if (cr > 7 && cm <= 14) {
				co = (cq + cp * 2) + "px"
			} else {
				if (cn > 7) {
					co = (cq + cp) + "px"
				} else {
					co = cq + "px"
				}
			}
		}
		document.getElementById("sear-sel-bd").style.height = co;
		$("#show_more").parent().css("top", "220px")
	}

	function d() {
		if (train_tour_flag == "fc" || (train_tour_flag == "gc" && canChangeToStation != "Y")) {
			return
		}
		var cm = ["fromStation", "toStation"];
		if (canChangeToStation == "Y") {
			cm = ["toStation"]
		}
		$.stationFor12306.init(cm, {
			_init_input: "简拼/全拼/汉字",
			_top_4_initInput: "简拼/全拼/汉字或↑↓",
			_unselected_class: "inpt_unselected",
			_selected_class: "inp_selected",
			confirmCallBack: function(cn, co) {
				$("#yxtrain_close").click();
				cn.removeClass("error");
				if (cn.attr("id") == "fromStationText") {
					if (ccSelected.length > 0) {
						if (cn.val() != bP) {
							$("#prior_train span:gt(1)").remove();
							$("#inp-train").css("color", "#999");
							$("#inp-train").val("  请输入");
							ccSelected = [];
							$("#prior_seat span:gt(0)").remove();
							$("#seat-list input").prop("checked", false);
							xbChecked = []
						}
					}
					bP = cn.val()
				}
				if (cn.attr("id") == "toStationText") {
					if (ccSelected.length > 0) {
						if (cn.val() != b7) {
							$("#prior_train span:gt(1)").remove();
							$("#inp-train").css("color", "#999");
							$("#inp-train").val("  请输入");
							ccSelected = [];
							$("#prior_seat span:gt(0)").remove();
							$("#seat-list input").prop("checked", false);
							xbChecked = []
						}
					}
					b7 = cn.val()
				}
			}
		});
		$("#fromStation_icon_image").css("cursor", "pointer");
		$("#fromStationText_label").click(function() {
			$("#fromStationText").focus()
		});
		$("#fromStation_icon_image").click(function() {
			$("#fromStationText").focus()
		});
		$("#toStation_icon_image").css("cursor", "pointer");
		$("#toStationText_label").click(function() {
			$("#toStationText").focus()
		});
		$("#toStation_icon_image").click(function() {
			$("#toStationText").focus()
		})
	}

	function cj() {
		bb = $("#queryLeftForm").validate({
			rules: {
				"leftTicketDTO.from_station": {
					required: true
				},
				"leftTicketDTO.to_station": {
					required: true
				},
				"leftTicketDTO.train_date": {
					required: true
				},
				back_train_date: {
					required: true
				}
			},
			ignore: "",
			onsubmit: false,
			onfocusout: function() {},
			onkeyup: function() {},
			onclick: function() {},
			highlight: function() {},
			unhighlight: function() {}
		});
		bK()
	}

	function b(cm) {
		dhtmlx.alert({
			title: "提示",
			ok: messages["button.ok"],
			text: cm,
			type: "alert-error",
			callback: function() {}
		})
	}

	function bI(cn, ct) {
		var cm = bb.checkForm();
		bb.hideErrors();
		if (cm) {
			var cs = "";
			if (!bC()) {
				cs = "返回日期不得早于出发日期";
				b(cs);
				return false
			}
			var cq = [];
			if (ct) {
				cq = stu_buy_date.split("&")
			} else {
				cq = other_buy_date.split("&")
			}
			if (cq.length > 0) {
				if (cn < cq[0] || cn > cq[1]) {
					cs = "您选择的日期不在预售期范围内！";
					b(cs);
					return false
				}
			}
		} else {
			var cr = bb.errorList;
			for (var cp = 0; cp < cr.length; cp++) {
				var co = cr[cp];
				$(co.element).next().addClass("error")
			}
			return false
		}
		cc();
		return true
	}

	function cc() {
		$.jc_setFromStation($("#fromStationText").val(), $("#fromStation").val());
		$.jc_setToStation($("#toStationText").val(), $("#toStation").val());
		$.jc_setFromDate($("#train_date").val());
		$.jc_setToDate($("#back_train_date").val());
		$.jc_setWfOrDc($("#wf").is(":checked") ? "wf" : "dc")
	}

	function bK() {
		$("#query_ticket").unbind("click").click(function(cq) {
			$("#sel-buyer").hide();
			$("#sel-seat").hide();
			$("#sel-date").hide();
			if ($("#yxtrain_loading").is(":hidden")) {
				$("#yxtraindiv").hide()
			}
			if ($jpopup.isShow()) {
				$jpopup.quickHide()
			}
			if (myStopStation) {
				myStopStation.close()
			}
			if ($("#auto_query").is(":checked")) {
				var cp = $.trim($("#inp-train").val()).toUpperCase();
				if (cp.length != 0 && cp != "请输入") {
					dhtmlx.alert({
						title: "输入车次",
						ok: "确定",
						text: "您输入的优先车次未添加，请点击车次输入框后的添加按钮，或者取消车次输入框中的内容！",
						type: "alert-error",
						callback: function() {
							ccInputSelected = true;
							$("#inp-train").select()
						}
					});
					return
				}
			}
			ah();
			if (document.getElementById("autoSubmit").checked) {
				if (passengerChecked.length == 0) {
					dhtmlx.alert({
						title: "选择乘车人",
						ok: "确定",
						text: "请选择乘车人",
						type: "alert-error",
						callback: function() {
							return
						}
					});
					return
				}
			}
			x = ch();
			var cr = x == "0X00" ? true : false;
			var cn = train_tour_flag == "fc" ? $.trim($("#back_train_date").val()) : $.trim($("#train_date").val());
			var cm = bI(cn, cr);
			if (!cm) {
				return
			}
			var co = {
				"leftTicketDTO.train_date": cn,
				"leftTicketDTO.from_station": $("#fromStation").val(),
				"leftTicketDTO.to_station": $("#toStation").val(),
				purpose_codes: x
			};
			aT();
			aj(co)
		})
	}
	var bf = function() {
		if ($("#filterTic").is(":checked")) {
			$("#avail_ticket").attr("checked", false);
			aK();
			if (bJ.length != 0 && bJ.length < a8.length) {
				$("#trainum").html(bJ.length);
				aA(bJ)
			}
		} else {
			bO = bc();
			if (bJ.length != 0 && bJ.length < bO.length) {
				$("#trainum").html(bO.length);
				aA(bO)
			}
		}
	};

	function b2(cp, cr) {
		var co = [];
		for (var cn = 0; cn < cp.length; cn++) {
			var cs = [];
			var cm = cp[cn].split("|");
			cs.secretStr = cm[0];
			cs.buttonTextInfo = cm[1];
			var cq = [];
			cq.train_no = cm[2];
			cq.station_train_code = cm[3];
			cq.start_station_telecode = cm[4];
			cq.end_station_telecode = cm[5];
			cq.from_station_telecode = cm[6];
			cq.to_station_telecode = cm[7];
			cq.start_time = cm[8];
			cq.arrive_time = cm[9];
			cq.lishi = cm[10];
			cq.canWebBuy = cm[11];
			cq.yp_info = cm[12];
			cq.start_train_date = cm[13];
			cq.train_seat_feature = cm[14];
			cq.location_code = cm[15];
			cq.from_station_no = cm[16];
			cq.to_station_no = cm[17];
			cq.is_support_card = cm[18];
			cq.controlled_train_flag = cm[19];
			cq.gg_num = cm[20] ? cm[20] : "--";
			cq.gr_num = cm[21] ? cm[21] : "--";
			cq.qt_num = cm[22] ? cm[22] : "--";
			cq.rw_num = cm[23] ? cm[23] : "--";
			cq.rz_num = cm[24] ? cm[24] : "--";
			cq.tz_num = cm[25] ? cm[25] : "--";
			cq.wz_num = cm[26] ? cm[26] : "--";
			cq.yb_num = cm[27] ? cm[27] : "--";
			cq.yw_num = cm[28] ? cm[28] : "--";
			cq.yz_num = cm[29] ? cm[29] : "--";
			cq.ze_num = cm[30] ? cm[30] : "--";
			cq.zy_num = cm[31] ? cm[31] : "--";
			cq.swz_num = cm[32] ? cm[32] : "--";
			cq.srrb_num = cm[33] ? cm[33] : "--";
			cq.yp_ex = cm[34];
			cq.seat_types = cm[35];
			cq.from_station_name = cr[cm[6]];
			cq.to_station_name = cr[cm[7]];
			cs.queryLeftNewDTO = cq;
			co.push(cs)
		}
		return co
	}

	function aj(cm) {
		$("#cc_seat_type_btn_all>ul>li").css("display", "none");
		if ($("#auto_query").is(":checked")) {
			$("#query_ticket").html("停止查询");
			$("#auto_query").attr("disabled", "true");
			$("#autoSubmit").attr("disabled", "true");
			$("#partSubmit").attr("disabled", "true");
			$("#query_ticket").unbind("click");
			$("#query_ticket").bind("click", function() {
				$("#filterTic").hide();
				clearInterval(aY);
				if (countDown) {
					clearInterval(countDown)
				}
				$("#filterTicDiv").html("");
				$("#query_ticket").unbind("click");
				$("#query_ticket").html("查询");
				if ($("#dc").is(":checked") && train_tour_flag != "gc") {
					$("#autoSubmit").removeAttr("disabled");
					$("#partSubmit").removeAttr("disabled")
				}
				$("#auto_query").removeAttr("disabled");
				bK()
			})
		} else {
			if (countDown) {
				clearInterval(countDown)
			}
			$("#filterTicDiv").html("");
			bN()
		}
		if ($("#yxtrain_loading").is(":hidden")) {
			var cn = dhtmlx.modalbox({
				targSrc: '<div><img src="' + ctx + 'resources/images/loading.gif"></img></div>',
				callback: function() {}
			})
		}
		if ($jpopup.isShow()) {
			$jpopup.quickHide()
		}
		$("#queryLeftTable").html("");
		$("#sear-result").hide();
		if (aY) {
			clearInterval(aY)
		}
		bX(cm);
		$.ajax({
			type: "get",
			isTakeParam: false,
			beforeSend: function(co) {
				co.setRequestHeader("If-Modified-Since", "0");
				co.setRequestHeader("Cache-Control", "no-cache")
			},
			url: ctx + CLeftTicketUrl,
			data: cm,
			timeout: 10000,
			error: function(co, cq, cp) {
				dhtmlx.modalbox.hide(cn);
				if ("timeout" == cq || "No Transport" == cq || "abort" == cq) {
					if ($("#auto_query").is(":checked")) {
						aj(cm)
					}
				}
			},
			success: function(cq) {
				dhtmlx.modalbox.hide(cn);
				if (cq.status) {
					if (cq.data == null || cq.data.length == 0) {
						$("#sear-sel").hide();
						$("#sear-result").hide();
						$("#t-list").hide();
						$("#no_filter_ticket_fromstation").html($("#fromStationText").val());
						$("#no_filter_ticket_tostation").html($("#toStationText").val());
						$("#no_filter_ticket_2").show();
						$(".content").css("min-height", "344px");
						$("#yxtraindiv").hide();
						trainListForIE = [];
						return
					}
					if (cq.data.flag == 1) {
						cq.data = b2(cq.data.result, cq.data.map)
					}
					trainListForIE = [];
					for (var cr = 0; cr < cq.data.length; cr++) {
						trainListForIE.push(cq.data[cr].queryLeftNewDTO.station_train_code + "(" + cq.data[cr].queryLeftNewDTO.start_time + "--" + cq.data[cr].queryLeftNewDTO.arrive_time + ")")
					}
					if (train_tour_flag == "gc" && "Y" == isDwTicketResign) {
						var cx = [];
						for (var cr = 0, cy = cq.data.length; cr < cy; cr++) {
							var cp = cq.data[cr].queryLeftNewDTO;
							var cu = cp.station_train_code;
							cu = cu.substring(0, 1);
							if ("G" == cu || "D" == cu) {
								cx.push(cq.data[cr])
							}
						}
						cq.data = cx
					}
					if ($("#DW_SHOW_STR")[0]) {
						$("#DW_SHOW_STR").remove()
					}
					if ($("#hainan_limit_msg")[0]) {
						$("#hainan_limit_msg").remove()
					}
					$("#sear-sel").show();
					$("#sear-result").show();
					$("#t-list").show();
					$("#no_filter_ticket_2").hide();
					$("#no_filter_ticket").hide();
					var co = "";
					var ct = "";
					if (train_tour_flag != null && train_tour_flag == "fc") {
						var cw = "<strong>".concat($("#fromStationText").val()).concat(" --> ").concat($("#toStationText").val()).concat("（").concat(aD($("#back_train_date").val())).concat('）</strong>共计<strong id="trainum">').concat(cq.data.length).concat("</strong>个车次");
						if (bV(cq.data)) {
							co = "<p class='ad-gt' id='DW_SHOW_STR' data='1'>高铁动卧 夕发朝至 风雨无阻 省时省钱</p>"
						} else {
							if (hainan_limit_msg && ae(cm, cq.data)) {
								ct = "<p class='ad-gt' id='hainan_limit_msg'  style='font-size:13px;background:#fff6f6 left center no-repeat;font-weight:bold'>" + hainan_limit_msg + "</p>"
							}
						}
						if ($("#auto_query").is(":checked")) {
							var cv = "";
							for (var cs = 0; cs < 25; cs++) {
								cv = cv + "&nbsp;"
							}
							cw = cw.concat(cv + "<input type='checkbox' class='check' id='filterTic' /><div id='filterTicDiv' style='display:inline'><strong><label for='filterTic' style='cursor: pointer;'>仅查看刷到车次</label></strong></div>")
						}
						$("#sear-result>p").html(cw);
						if ($("#auto_query").is(":checked")) {
							$("#filterTic").bind("click", bf)
						}
					} else {
						var cw = "<strong>".concat($("#fromStationText").val()).concat(" --> ").concat($("#toStationText").val()).concat("（").concat(aD($("#train_date").val())).concat('）</strong>共计<strong id="trainum">').concat(cq.data.length).concat("</strong>个车次");
						if (bV(cq.data)) {
							co = "<p class='ad-gt' id='DW_SHOW_STR' data='1'>高铁动卧 夕发朝至 风雨无阻 省时省钱</p>"
						} else {
							if (hainan_limit_msg && ae(cm, cq.data)) {
								ct = "<p class='ad-gt' id='hainan_limit_msg'  style='font-size:13px;background:#fff6f6 left center no-repeat;font-weight:bold'>" + hainan_limit_msg + "</p>"
							}
						}
						if ($("#auto_query").is(":checked")) {
							var cv = "";
							for (var cs = 0; cs < 25; cs++) {
								cv = cv + "&nbsp;"
							}
							cw = cw.concat(cv + "<input type='checkbox' class='check' id='filterTic' /><div id='filterTicDiv' style='display:inline'><strong><label for='filterTic' style='cursor: pointer;'>仅查看刷到车次</label></strong></div>")
						}
						$("#sear-result>p").html(cw);
						if ($("#auto_query").is(":checked")) {
							$("#filterTic").bind("click", bf)
						}
					}
					if (!$("#DW_SHOW_STR")[0]) {
						$("#sear-result>p").after(co)
					}
					if (ct) {
						$("#sear-result>p").after(ct)
					}
					if (dwTranTimeStr) {
						clearInterval(dwTranTimeStr)
					}
					if ($("#DW_SHOW_STR")[0]) {
						dwTranTimeStr = window.setInterval(function() {
							if ($("#DW_SHOW_STR").attr("data") == "1") {
								$("#DW_SHOW_STR").attr("data", "2").html("夜行两千公里 最低不足千元")
							} else {
								$("#DW_SHOW_STR").attr("data", "1").html("高铁动卧 夕发朝至 风雨无阻 省时省钱")
							}
						}, 1300)
					}
					if ($("#hainan_limit_msg")[0]) {
						hainan_tip = null;
						hainan_tip = new Marquee({
							ID: "hainan_limit_msg",
							Direction: "left",
							Step: 1,
							Width: 0,
							Height: 0,
							Timer: 30,
							DelayTime: 0,
							WaitTime: 0,
							ScrollStep: 0
						})
					}
					a8 = cq.data;
					bl(a8);
					n();
					bE(a8);
					bM();
					L();
					if (!$("#yxtrain_loading").is(":hidden")) {
						$.showYxTrainData()
					}
					yxTrainChange = $("#fromStationText").val() + $("#toStationText").val() + $("#train_date").val()
				} else {
					if (cq && cq.c_url) {
						CLeftTicketUrl = cq.c_url;
						aj(cm)
					}
				}
			},
			error: function(co) {
				dhtmlx.modalbox.hide(cn);
				if (co.status == 403) {
					if ($("#query_ticket").html() == "停止查询") {
						if (queryLeftTicket_times <= queryLeftTicket_count) {
							$("#query_ticket").trigger("click").trigger("click");
							queryLeftTicket_times++
						} else {
							queryLeftTicket_times = 0
						}
					}
				}
			}
		});
		aX()
	}

	function ab() {
		dataNumber = other_control > stu_control ? other_control : stu_control;
		for (var cm = endShow + 1; cm <= dataNumber; cm++) {
			$("#date_range>ul>li:nth-child(" + cm + ")").hide()
		}
		var cn;
		$("#date_range>ul>li").each(function(cr) {
			var cp = fullDateArr[cr];
			var co = new Date(Date.parse(cp.replace(/-/g, "/")));
			var cq = $("#date_range>ul>li:nth-child(" + (cr + 1) + ")>span[class=hide]").text().substring(0, 5) + bi(co);
			$("#date_range>ul>li:nth-child(" + (cr + 1) + ")>span[class=hide]").text(cq);
			cn = $(this).children("span:first-child").html();
			change_dates_arr.push(cn)
		});
		if (index_train_date == null) {
			$("#date_range>ul>li:nth-child(1)").addClass("sel");
			$("#date_range>ul>li:nth-child(1)").attr("alt", "show");
			$("#date_range>ul>li:nth-child(20)").addClass("end");
			$("#date_range>ul>li:nth-child(1)").children("span:first-child").removeClass();
			$("#date_range>ul>li:nth-child(1)").children("span:last-child").removeClass();
			$("#date_range>ul>li:nth-child(1)").children().addClass("first");
			$("#date_range>ul>li:nth-child(1)").children("span:first-child").addClass("hide");
			bR = $("#date_range>ul>li:nth-child(1)").children("span:first-child").text()
		}
		bg()
	}

	function bi(cn) {
		var cq = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];
		var cp = 0;
		for (var co = 0; co < cq.length; co++) {
			if (cn.toString().indexOf(cq[co]) > -1) {
				cp = co + 1;
				break
			}
		}
		var cm = "";
		switch (cp) {
			case 1:
				cm = " 周一";
				break;
			case 2:
				cm = " 周二";
				break;
			case 3:
				cm = " 周三";
				break;
			case 4:
				cm = " 周四";
				break;
			case 5:
				cm = " 周五";
				break;
			case 6:
				cm = " 周六";
				break;
			case 7:
				cm = " 周日";
				break
		}
		return cm
	}

	function bj() {
		$("#date_range>ul>li").unbind("mouseover");
		$("#date_range>ul>li").unbind("mouseout");
		$("#date_range").unbind("mouseleave");
		$("#date_range>ul>li").unbind("click")
	}

	function bg() {
		$("#date_range>ul>li").bind("mouseover", function() {
			$("#date_range>ul>li").removeClass("sel");
			$("#date_range>ul>li").removeAttr("alt");
			$(this).addClass("sel");
			$(this).attr("alt", "show");
			$("#date_range>ul>li:nth-child(" + endShow + ")").addClass("end");
			$(this).children("span:first-child").removeClass();
			$(this).children("span:last-child").removeClass();
			$("#date_range>ul>li:nth-child(" + firstShow + ")").children().addClass("first");
			$(this).children("span:first-child").addClass("hide")
		});
		$("#date_range>ul>li").bind("mouseout", function() {
			$("#date_range>ul>li").each(function(cm) {
				$(this).children("span:first").removeClass();
				$("#date_range>ul>li:nth-child(" + firstShow + ")").children().addClass("first");
				$(this).children("span:last").addClass("hide")
			})
		});
		$("#date_range").bind("mouseleave", function() {
			for (var cm = firstShow; cm <= endShow; cm++) {
				var cn = $("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").text();
				if (bR == cn) {
					$("#date_range>ul>li").removeClass("sel");
					$("#date_range>ul>li").removeAttr("alt");
					$("#date_range>ul>li:nth-child(" + cm + ")").addClass("sel");
					$("#date_range>ul>li:nth-child(" + cm + ")").attr("alt", "show");
					$("#date_range>ul>li:nth-child(" + endShow + ")").addClass("end");
					$("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").removeClass();
					$("#date_range>ul>li:nth-child(" + cm + ")").children("span:last-child").removeClass();
					$("#date_range>ul>li:nth-child(" + firstShow + ")").children().addClass("first");
					$("#date_range>ul>li:nth-child(" + cm + ")").children("span:first-child").addClass("hide");
					break
				}
			}
		});
		$("#date_range>ul>li").bind("click", function() {
			var cn = new Date();
			var cq = "";
			if (train_tour_flag != null && train_tour_flag == "fc") {
				nowDate = $("#back_train_date").val();
				var cs = $(this).children("span:first-child").text();
				var cm = Number(cs.substring(0, 2));
				var cu = new Date().getMonth();
				var cp = cn.getFullYear();
				if (cu > cm) {
					cp = cp + 1
				}
				$("#back_train_date").val(cp + "-" + cs);
				backTrainDate = cp + "-" + cs;
				cq = backTrainDate;
				if (!bC()) {
					$("#back_train_date").val(nowDate);
					b("返程日期不得小于出发日期.");
					return
				}
				z("back_train_date")
			} else {
				nowDate = $("#train_date").val();
				var cs = $(this).children("span:first-child").text();
				var cm = Number(cs.substring(0, 2));
				var cu = new Date().getMonth();
				var cp = cn.getFullYear();
				if (cu > cm) {
					cp = cp + 1
				}
				$("#train_date").val(cp + "-" + cs);
				trainDate = cp + "-" + cs;
				cq = trainDate;
				if (!bC()) {
					$("#back_train_date").val($("#train_date").val())
				}
				z("train_date")
			}
			x = ch();
			var cr = x == "0X00" ? true : false;
			var ct = bI(cq, cr);
			if (!ct) {
				return
			}
			$("#date_range>ul>li").removeClass("sel");
			$("#date_range>ul>li").removeAttr("alt");
			$(this).addClass("sel");
			$(this).attr("alt", "show");
			$("#date_range>ul>li:nth-child(20)").addClass("end");
			$(this).children("span:first-child").removeClass();
			$(this).children("span:last-child").removeClass();
			$("#date_range>ul>li:nth-child(1)").children().addClass("first");
			$(this).children("span:first-child").addClass("hide");
			bR = $(this).children("span:first-child").text();
			var co = {
				"leftTicketDTO.train_date": cq,
				"leftTicketDTO.from_station": $("#fromStation").val(),
				"leftTicketDTO.to_station": $("#toStation").val(),
				purpose_codes: ch()
			};
			aj(co)
		});
		$("#sf1").click(function() {
			isOther = true;
			aT();
			if (other_control < dataNumber) {
				for (var cm = other_control + 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").hide()
				}
			} else {
				for (var cm = 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").show()
				}
			}
		});
		$("#sf2").click(function() {
			isOther = false;
			aT();
			if (stu_control < dataNumber) {
				for (var cm = stu_control; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").hide()
				}
			} else {
				for (var cm = 1; cm <= dataNumber; cm++) {
					$("#date-list>li:nth-child(" + cm + ")").show()
				}
			}
		})
	}

	function bu() {
		$("#sear-sel-bd input[name='cc_type']").click(function() {
			var cm = $("input[name='cc_type']");
			var cn = $("input[name='cc_type']:checked");
			if ($(this).is(":checked")) {
				if (cm && cn && cn.length == cm.length) {
					$("#train_type_btn_all").removeClass().addClass("btn-all")
				} else {
					$("#train_type_btn_all").removeClass().addClass("btn-all btn-all-sel")
				}
			} else {
				if (cm && cn && cn.length == 0) {
					$("#train_type_btn_all").removeClass().addClass("btn-all")
				} else {
					$("#train_type_btn_all").removeClass().addClass("btn-all btn-all-sel")
				}
			}
			aH()
		});
		$("#sear-sel-bd input[name='cc_start_time']").click(function() {
			var cm = $("input[name='cc_start_time']");
			var cn = $("input[name='cc_start_time']:checked");
			if ($(this).is(":checked")) {
				if (cm && cn && cn.length == cm.length) {
					$("#start_time_btn_all").removeClass().addClass("btn-all")
				} else {
					$("#start_time_btn_all").removeClass().addClass("btn-all btn-all-sel")
				}
			} else {
				if (cm && cn && cn.length == 0) {
					$("#start_time_btn_all").removeClass().addClass("btn-all")
				} else {
					$("#start_time_btn_all").removeClass().addClass("btn-all btn-all-sel")
				}
			}
			aH()
		});
		$("#sear-sel-bd input[name='cc_arrive_time']").click(function() {
			var cm = $("input[name='cc_arrive_time']");
			var cn = $("input[name='cc_arrive_time']:checked");
			if ($(this).is(":checked")) {
				if (cm && cn && cn.length == cm.length) {
					$("#arrive_time_btn_all").removeClass().addClass("btn-all")
				} else {
					$("#arrive_time_btn_all").removeClass().addClass("btn-all btn-all-sel")
				}
			} else {
				if (cm && cn && cn.length == 0) {
					$("#arrive_time_btn_all").removeClass().addClass("btn-all")
				} else {
					$("#arrive_time_btn_all").removeClass().addClass("btn-all btn-all-sel")
				}
			}
			aH()
		});
		$("#cc_start_time").change(function() {
			aH()
		})
	}

	function Q(co, cn) {
		if (cn.length == 0) {
			return true
		}
		for (var cm = 0; cm < cn.length; cm++) {
			if (co.queryLeftNewDTO.station_train_code.substring(0, 1) == cn[cm]) {
				return true
			}
			if (cn[cm] == "QT") {
				if (co.queryLeftNewDTO.station_train_code.substring(0, 1) != "G" && co.queryLeftNewDTO.station_train_code.substring(0, 1) != "D" && co.queryLeftNewDTO.station_train_code.substring(0, 1) != "C" && co.queryLeftNewDTO.station_train_code.substring(0, 1) != "T" && co.queryLeftNewDTO.station_train_code.substring(0, 1) != "K" && co.queryLeftNewDTO.station_train_code.substring(0, 1) != "Z") {
					return true
				}
			}
			if (cn[cm] == "G") {
				if (co.queryLeftNewDTO.station_train_code.substring(0, 1) == "C" || co.queryLeftNewDTO.station_train_code.substring(0, 1) == "G") {
					return true
				}
			}
		}
		return false
	}

	function aI(cp, cr) {
		if (cr.length == 0) {
			return true
		}
		for (var cm = 0; cm < cr.length; cm++) {
			var cq = (cp.queryLeftNewDTO.start_time.replace(":", ""));
			var cn = Number(cr[cm].substring(0, 4));
			var co = Number(cr[cm].substring(4, 8));
			if (cq >= cn && cq <= co) {
				return true
			}
		}
		return false
	}

	function aQ(co, cm) {
		if (cm.length == 0) {
			return true
		}
		for (var cn = 0; cn < cm.length; cn++) {
			if (cm[cn] == "SWZ") {
				if (co.queryLeftNewDTO.swz_num != "--" && co.queryLeftNewDTO.swz_num != "无") {
					aC.push("SWZ");
					return true
				}
			}
			if (cm[cn] == "TZ") {
				if (co.queryLeftNewDTO.tz_num != "--" && co.queryLeftNewDTO.tz_num != "无") {
					aC.push("TZ");
					return true
				}
			}
			if (cm[cn] == "ZY") {
				if (co.queryLeftNewDTO.zy_num != "--" && co.queryLeftNewDTO.zy_num != "无") {
					aC.push("ZY");
					return true
				}
			}
			if (cm[cn] == "ZE") {
				if (co.queryLeftNewDTO.ze_num != "--" && co.queryLeftNewDTO.ze_num != "无") {
					aC.push("ZE");
					return true
				}
			}
			if (cm[cn] == "GR") {
				if (co.queryLeftNewDTO.gr_num != "--" && co.queryLeftNewDTO.gr_num != "无") {
					aC.push("GR");
					return true
				}
			}
			if (cm[cn] == "RW") {
				if (co.queryLeftNewDTO.rw_num != "--" && co.queryLeftNewDTO.rw_num != "无") {
					aC.push("RW");
					return true
				}
			}
			if (cm[cn] == "YW") {
				if (co.queryLeftNewDTO.yw_num != "--" && co.queryLeftNewDTO.yw_num != "无") {
					aC.push("YW");
					return true
				}
			}
			if (cm[cn] == "RZ") {
				if (co.queryLeftNewDTO.rz_num != "--" && co.queryLeftNewDTO.rz_num != "无") {
					aC.push("RZ");
					return true
				}
			}
			if (cm[cn] == "YZ") {
				if (co.queryLeftNewDTO.yz_num != "--" && co.queryLeftNewDTO.yz_num != "无") {
					aC.push("YZ");
					return true
				}
			}
			if (cm[cn] == "SRRB") {
				if (co.queryLeftNewDTO.srrb_num != "--" && co.queryLeftNewDTO.srrb_num != "无") {
					aC.push("SRRB");
					return true
				}
			}
			if (cm[cn] == "YYRW") {
				if (co.queryLeftNewDTO.yyrw_num != "--" && co.queryLeftNewDTO.yyrw_num != "无") {
					aC.push("YYRW");
					return true
				}
			}
			if (cm[cn] == "WZ") {
				if (co.queryLeftNewDTO.wz_num != "--" && co.queryLeftNewDTO.wz_num != "无") {
					aC.push("WZ");
					return true
				}
			}
		}
		return false
	}

	function a7(cn, cm) {
		if (cm.length == 0) {
			return true
		}
		for (var co = 0; co < cm.length; co++) {
			if (cm[co] == cn.queryLeftNewDTO.from_station_name) {
				return true
			}
		}
		return false
	}

	function V(cm, cn) {
		if (cn.length == 0) {
			return true
		}
		for (var co = 0; co < cn.length; co++) {
			if (cn[co] == cm.queryLeftNewDTO.to_station_name) {
				return true
			}
		}
		return false
	}

	function w(cn, cm) {
		if (cm.length == 0) {
			return true
		}
		for (var co = 0; co < cm.length; co++) {
			if (cm[co].toLowerCase() == cn.queryLeftNewDTO.station_train_code.toLowerCase()) {
				return true
			}
		}
		return false
	}
	window._tpp_ = "abcdefghIjkLm nopqrstuvwxiyz";

	function bc() {
		var cn = [];
		var ct = [];
		var cp = [];
		var cr = [];
		$("#sear-sel-bd input[name='cc_type']").each(function() {
			if (this.checked == true) {
				cn.push($(this).val())
			}
		});
		ct.push($("#cc_start_time option:selected").val());
		$("#sear-sel-bd input[name='cc_from_station']").each(function() {
			if (this.checked == true) {
				cp.push($(this).val())
			}
		});
		$("#sear-sel-bd input[name='cc_to_station']").each(function() {
			if (this.checked == true) {
				cr.push($(this).val())
			}
		});
		var co = a8;
		var cs = [];
		if (cn.length > 0 || ct.length > 0 || filteredTrainArriveTime.length > 0 || bQ.length > 0 || cp.length > 0 || cr.length > 0 || ax.getComboText() != "" || $("#avail_ticket")[0].checked) {
			for (var cm = 0; cm < co.length; cm++) {
				var cq = co[cm];
				if (!Q(cq, cn)) {
					continue
				}
				if (!aI(cq, ct)) {
					continue
				}
				if (!a7(cq, cp)) {
					continue
				}
				if (!V(cq, cr)) {
					continue
				}
				if ($("#avail_ticket")[0].checked) {
					if (cq.queryLeftNewDTO.canWebBuy == "Y") {
						cs.push(cq)
					}
				} else {
					cs.push(cq)
				}
			}
			co = cs
		}
		return co
	}(function(cm) {
		cm._Z_ = cm._Z_ || {};
		cm._Z_["YLW"] = function() {
			var cn = "";
			pp = [25, 21, 7, 6, 14, 25, 9, 13, 4, 22, 15, 11, 13, 8];
			while (pp[0]) {
				cn += cm._tpp_.charAt(pp.pop())
			}
			return cn
		}
	})(window);

	function I(cm, cn) {
		if (cn == null || cn == "" || cm.length == 0 || cn.length > cm.length) {
			return false
		}
		if (cm.substr(0, cn.length) == cn) {
			return true
		} else {
			return false
		}
		return true
	}

	function a4(cm) {
		be = ccSelected;
		bQ = xbChecked;
		if (w(cm, be) && aQ(cm, bQ)) {
			return true
		} else {
			return false
		}
	}

	function aK() {
		bJ = [];
		bO = bc();
		bY = bS(bO);
		for (var cm = 0; cm < bY.length; cm++) {
			var cn = bY[cm];
			if (!a4(cn)) {
				continue
			}
			if (cn.queryLeftNewDTO.canWebBuy == "Y") {
				bJ.push(cn)
			}
		}
	}
	var by;

	function bF() {
		if (ischeckAutoSubmitCode) {
			$("#randCode2").on("keyup", function(cm) {
				if ($("#randCode2").val().length == 4 && by != $("#randCode2").val()) {
					$.ajax({
						url: ctx + "passcodeNew/checkRandCodeAnsyn",
						type: "post",
						data: {
							randCode: $("#randCode2").val(),
							rand: "sjrand"
						},
						async: false,
						success: function(co) {
							if (co.data == "N") {
								$("#randCode2").removeClass("inptxt w100").addClass("inptxt w100 error");
								$("#c_error2").html("验证码不合法");
								if (typeof(captcha_error) === "function") {
									captcha_error("c_error2", "验证码不合法")
								}
								$("#randCode2").val("");
								$("#c_error2").addClass("error");
								$("#i-ok2").css("display", "none");
								$("#c_error2").css("margin-left", "15px")
							} else {
								by = $("#randCode2").val();
								$("#back_edit").trigger("click");
								var cn = "99999GGGGG";
								var cq = "##CCT##PPT##CPT##PXT##SBT##PBD##JOD##HPD##SHD##QTP##TSP##TJP##";
								var cp = "##CBP##DIP##JGK##ZEK##UUH##NKH##ESH##OHH##AOH##";
								if (isAsync == ticket_submit_order.request_flag.isAsync) {
									if (K.queryLeftNewDTO.train_no.indexOf(cn) > -1 && cq.indexOf(K.queryLeftNewDTO.from_station_telecode) > -1 && cp.indexOf(K.queryLeftNewDTO.to_station_telecode) > -1) {
										dhtmlx.createWin({
											winId: "confirmG1234",
											closeWinId: ["close_conifrmdialog_G1234", "cancel_dialog_G1234"],
											okId: "goto_integration_G1234",
											okCallBack: function() {
												q()
											},
											callback: function() {
												return
											}
										})
									} else {
										q()
									}
								} else {
									if (K.queryLeftNewDTO.train_no.indexOf(cn) > -1 && cq.indexOf(K.queryLeftNewDTO.from_station_telecode) > -1 && cp.indexOf(K.queryLeftNewDTO.to_station_telecode) > -1) {
										dhtmlx.createWin({
											winId: "confirmG1234",
											closeWinId: ["close_conifrmdialog_G1234", "cancel_dialog_G1234"],
											okId: "goto_integration_G1234",
											okCallBack: function() {
												ck()
											},
											callback: function() {
												return
											}
										})
									} else {
										ck()
									}
								}
								$("#randCode2").removeClass("inptxt w100 error").addClass("inptxt w100");
								$("#i-ok2").css("display", "block");
								$("#c_error2").html("");
								$("#c_error2").removeClass("error");
								return
							}
						}
					})
				} else {
					if ($("#randCode2").val().length != 4) {
						$("#randCode2").removeClass("inptxt w100").addClass("inptxt w100 error");
						$("#c_error2").html("请输入四位长度验证码");
						$("#c_error2").addClass("error");
						$("#i-ok2").css("display", "none");
						$("#c_error2").css("margin-left", "15px")
					}
				}
				by = $("#randCode2").val()
			})
		}
	}

	function al(cm) {
		return aN.autoSubmit(bJ, passengerChecked, xbChecked, ccSelected)
	}
	var aO = false;

	function L() {
		$("#queryLeftTable").html("");
		$("#trainum").html("");
		aK();
		if ($("#auto_query").is(":checked")) {
			if (bY.length < 0) {
				$("#no_filter_ticket").show();
				$("#trainum").html("0");
				aO = true
			} else {
				if (bJ.length > 0) {
					$("#no_filter_ticket").hide();
					if (document.getElementById("autoSubmit").checked) {
						var cq = [];
						for (var cw = 0; cw < passengerChecked.length; cw++) {
							var cp = false;
							var ct = passengerChecked[cw];
							for (var cx = 0; cx < cq.length; cx++) {
								var cn = cq[cx];
								if (ct.passenger_type != 2) {
									if (ct.passenger_name == cn.passenger_name && ct.passenger_id_type_code == cn.passenger_id_type_code && ct.passenger_id_no == cn.passenger_id_no) {
										if (cn.passenger_type != 2) {
											cp = true;
											break
										}
									}
								}
							}
							if (!cp) {
								cq.push(ct)
							}
						}
						passengerChecked = cq;
						var cC = al(true);
						if (cC[0] == 1 || cC[0] == 2) {
							aO = true;
							K = cC[1];
							var cv = ch();
							var cz = K.secretStr;
							m(cC);
							var cy = checkusermdId != undefined ? "&_json_att=" + encodeURIComponent(checkusermdId) : "";
							var cm = "";
							if ($("#dc").is(":checked")) {
								cm = "dc"
							} else {
								cm = "wc"
							}
							if ("undefined" == typeof(submitForm)) {
								var cD = "secretStr=" + cz + "&train_date=" + $("#train_date").val() + "&tour_flag=" + cm + "&purpose_codes=" + cv + "&query_from_station_name=" + $("#fromStationText").val() + "&query_to_station_name=" + $("#toStationText").val() + "&" + cy + "&cancel_flag=2&bed_level_order_num=000000000000000000000000000000&passengerTicketStr=" + getpassengerTicketsForAutoSubmit() + "&oldPassengerStr=" + getOldPassengersForAutoSubmit()
							} else {
								var co = submitForm();
								var cu = co.split(":::");
								var cB = cu[0].split(",-,")[0];
								var cs = cu[0].split(",-,")[1];
								var cA = cu[1].split(",-,")[0];
								var cr = cu[1].split(",-,")[1];
								var cD = escape(cB) + "=" + escape(cs) + "&" + cA + "=" + cr + "&secretStr=" + cz + "&train_date=" + $("#train_date").val() + "&tour_flag=" + cm + "&purpose_codes=" + cv + "&query_from_station_name=" + $("#fromStationText").val() + "&query_to_station_name=" + $("#toStationText").val() + "&" + cy + "&cancel_flag=2&bed_level_order_num=000000000000000000000000000000&passengerTicketStr=" + getpassengerTicketsForAutoSubmit() + "&oldPassengerStr=" + getOldPassengersForAutoSubmit()
							}
							$.ajax({
								type: "post",
								url: ctx + "confirmPassenger/autoSubmitOrderRequest",
								async: false,
								data: cD,
								success: function(cE) {
									if (cE.status) {
										if (!cE.data.submitStatus) {
											if (cE.data.isRelogin) {
												window.location.href = ctx + "login/init?random=" + new Date().getTime()
											} else {
												if (cE.data.isNoActive) {
													ac(cE.data.errMsg, true, "", true, "warn")
												} else {
													if (cE.data.checkSeatNum) {
														ac("很抱歉，无法提交您的订单!", true, "原因： " + cE.data.errMsg, true, "warn")
													} else {
														ac("车票信息不合法!", true, "原因： " + cE.data.errMsg, true, "warn")
													}
												}
											}
											return
										}
										intervalTime = cE.data.ifShowPassCodeTime;
										if (cE.data.ifShowPassCode == "Y") {
											bG(true)
										} else {
											bG(false)
										}
										canChooseSeats = cE.data.canChooseSeats;
										choose_Seats = cE.data.choose_Seats;
										canChooseBeds = cE.data.canChooseBeds;
										isCanChooseMid = cE.data.isCanChooseMid;
										if (cE.data.smokeStr != "" && cE.data.smokeStr.length > 0) {
											$("#dialog_smoker_msg").html(cE.data.smokeStr);
											dhtmlx.createWin({
												winId: "dialog_smoker",
												closeWinId: ["dialog_smoker_close", "dialog_smoker_cancel"],
												okId: "dialog_smoker_ok",
												okCallBack: function() {
													l(cE, cv)
												},
												checkConfirm: function() {
													return true
												},
												callback: function() {}
											})
										} else {
											l(cE, cv)
										}
									}
								}
							})
						} else {
							aO = false;
							M()
						}
					} else {
						aO = true
					}
				} else {
					aO = false;
					M()
				}
				$("#trainum").html(bY.length);
				aA(bY)
			}
		} else {
			if (bY.length < 0) {
				aO = true;
				$("#no_filter_ticket").show();
				$("#no_filter_ticket_msg_1").show();
				$("#no_filter_ticket_msg_2").hide();
				$("#trainum").html("0");
				return
			} else {
				aO = true;
				$("#trainum").html(bY.length);
				aA(bY)
			}
		}
	}

	function l(cn, co) {
		if (cn.data.isNeedPassCode == "N") {
			$("#leftTicketOrderNote").hide();
			$("#qr_submit").nextAll("a").eq(0).hide();
			ischeckAutoSubmitCode = false
		} else {
			$("#leftTicketOrderNote").show();
			$("#qr_submit").nextAll("a").eq(0).show();
			ischeckAutoSubmitCode = true
		}
		if (cn.data && undefined != cn.data.result && typeof(cn.data.result) != "undefined") {
			var cp = cn.data.get608Msg;
			if (undefined != cp && typeof(cp) != "undefined" && "" != cp) {
				if (cn.data.name && cn.data.card && cn.data.tel) {
					$("#608_check_msg").html(cp);
					dhtmlx.createWin({
						winId: "608_check",
						closeWinId: ["608_check_close", "608_check_cancel"],
						okId: "608_check_ok",
						okCallBack: function() {
							$("#608_name").html(cn.data.name);
							$("#608_card").html(cn.data.card);
							$("#608_tel").html(cn.data.tel);
							$("#ticketInfo").html(cn.data.ticketInfo);
							dhtmlx.createWin({
								winId: "608_complain",
								closeWinId: ["608_complain_close", "608_complain_cancel"],
								okId: "608_complain_ok",
								okCallBack: function() {
									var cq = dhtmlx.modalbox({
										targSrc: '<div><img src="' + ctx + 'resources/images/loading.gif"></img></div>',
										callback: function() {}
									});
									$.ajax({
										url: ctx + "confirmPassenger/report",
										type: "post",
										async: false,
										success: function(cr) {
											dhtmlx.modalbox.hide(cq);
											dhtmlx.alert({
												title: "提示",
												ok: messages["button.ok"],
												text: cr.data == "Y" ? "举报成功" : "举报失败",
												type: "alert-info"
											})
										},
										error: function(cr, ct, cs) {
											dhtmlx.modalbox.hide(cq)
										}
									})
								},
								checkConfirm: function() {
									return true
								}
							});
							$("#608_complain").css("top", "200px")
						},
						checkConfirm: function() {
							return true
						}
					});
					$("#608_check").css("top", "200px")
				} else {
					dhtmlx.alert({
						title: "警告",
						ok: "确定",
						text: cp,
						type: "alert-error",
						callback: function() {
							var cq = cn.data.result;
							location_code = cq.split("#")[0];
							md5Str = cq.split("#")[1];
							leftTicketStr = cq.split("#")[2];
							isAsync = cq.split("#")[3];
							bq(co, cn.data.isCheckOrderInfo, cn.data.doneHMD)
						}
					})
				}
			} else {
				var cm = cn.data.result;
				location_code = cm.split("#")[0];
				md5Str = cm.split("#")[1];
				leftTicketStr = cm.split("#")[2];
				isAsync = cm.split("#")[3];
				bq(co, cn.data.isCheckOrderInfo, cn.data.doneHMD)
			}
		}
	}
	var O = 0;
	var aY;

	function M() {
		var cm;
		if (rqChecked.length > 1) {
			if (O >= rqChecked.length) {
				O = 0
			}
			cm = rqChecked[O++]
		} else {
			if (train_tour_flag == "fc") {
				cm = $.trim($("#back_train_date").val())
			} else {
				cm = $.trim($("#train_date").val())
			}
		}
		clearInterval(aY);
		aY = window.setInterval(function() {
			if (train_tour_flag == "fc") {
				$("#back_train_date").val(cm)
			} else {
				$("#train_date").val(cm)
			}
			var cn = {
				"leftTicketDTO.train_date": cm,
				"leftTicketDTO.from_station": $("#fromStation").val(),
				"leftTicketDTO.to_station": $("#toStation").val(),
				purpose_codes: ch()
			};
			aT();
			aj(cn)
		}, autoSearchTime)
	}

	function h() {
		if (ifAlertCode && !verifyRandCode($("#randCode_other")[0], true)) {
			return
		}
		var cm = bD();
		if (cm.length == 0 || tickets_info.length == cm.length / 2) {
			$("#content_autosubmitcheckticketinfo").hide();
			loadGrayBackground();
			if (isAsync == ticket_submit_order.request_flag.isAsync) {
				q()
			} else {
				ck()
			}
		} else {
			dhtmlx.alert({
				title: "警告",
				ok: "确定",
				text: "您还有未选座的乘客，请选座完成后再提交订单！",
				type: "alert-error",
				callback: function() {}
			})
		}
	}

	function bU() {
		aw();
		cg(tickets_info);
		T();
		b6();
		$("#i-ok2").hide();
		if (ifAlertCode) {
			refreshImg("passenger", "randp", "other")
		}
		$("#error_msgmypasscode2").hide();
		$("#content_autosubmitcheckticketinfo").show();
		box = dhtmlx.createWin({
			winId: "autosubmitcheckticketinfo",
			closeWinId: ["back_edit"],
			callback: function() {
				clearTimeout(aG);
				jPlayer("stop")
			},
			okId: "qr_submit",
			okCallBack: function() {
				jPlayer("stop");
				if (isAsync == ticket_submit_order.request_flag.isAsync) {
					q()
				} else {
					ck()
				}
			},
			checkConfirm: function() {
				if (!bk()) {
					return false
				}
				if (!ischeckAutoSubmitCode) {
					return true
				}
				if (ifAlertCode) {
					return verifyRandCode($("#randCode_other")[0], true)
				} else {
					if (isAsync == ticket_submit_order.request_flag.isAsync) {
						q()
					} else {
						ck()
					}
				}
			}
		});
		var cn = parseInt(intervalTime / timer_time);
		if (!ifAlertCode) {
			ai(timer_time, cn)
		} else {
			var cm = $("#qr_submit1");
			cm.unbind("click");
			cm.removeClass("btn92s").addClass("btn92");
			aF(timer_time, cn)
		}
		if (tickets_info.length > 3 && canChooseSeats && "Y" == canChooseSeats) {
			$("#autosubmitcheckticketinfo").css("top", "70px")
		} else {
			$("#autosubmitcheckticketinfo").css("top", "100px")
		}
		$("#autosubmitcheckticketinfo").css("position", "absolute");
		$(".dhx_modal_cover").css("background-color", "#EEEEEE");
		$("#randCode_other").focus()
	}
	var aG;

	function ai(cn, cm) {
		if (cn == 0) {
			clearTimeout(aG);
			h();
			return
		} else {
			cn--
		}
		aG = setTimeout(function() {
			ai(cn, cm)
		}, cm)
	}
	var br;

	function aF(co, cn) {
		if (co == 0) {
			clearTimeout(br);
			var cm = $("#qr_submit1");
			cm.unbind("click").bind("click", h);
			cm.removeClass("btn92").addClass("btn92s");
			return
		} else {
			co--
		}
		br = setTimeout(function() {
			aF(co, cn)
		}, cn)
	}

	function aH() {
		if (a8.length == 0) {
			return
		}
		var cm = bc();
		var cn = bS(cm);
		$("#train_stop").appendTo($("body")).hide();
		$("#queryLeftTable").html("");
		$("#trainum").html("");
		if (cn.length > 0) {
			$("#no_filter_ticket").hide();
			$("#trainum").html(cn.length)
		} else {
			$("#no_filter_ticket").show();
			$("#no_filter_ticket_msg_1").show();
			$("#no_filter_ticket_msg_2").hide();
			$("#trainum").html("0");
			return
		}
		aA(cn)
	}

	function bv(cn) {
		var cm = b9.createWindow(cn + "_", 0, 0, 660, 100);
		cm.attachObject(cn);
		cm.clearIcon();
		cm.denyResize();
		cm.setModal(true);
		cm.center();
		cm.button("park").hide();
		cm.button("minmax1").hide();
		cm.hideHeader();
		return cm
	}

	function aw() {
		var cr = new Array();
		$("#autosubmit_check_ticket_tit").html("");
		var cp = $("#train_date").val();
		var cm = bi(new Date(Date.parse(cp.replace(/-/g, "/"))));
		var cn = K.queryLeftNewDTO.station_train_code;
		var cw = null;
		var cx = K.queryLeftNewDTO.from_station_name;
		var cq = K.queryLeftNewDTO.to_station_name;
		var cs = K.queryLeftNewDTO.start_time;
		var cv = K.queryLeftNewDTO.arrive_time;
		var cu = function(cz, cB, cy, cD, cA, cC, cF, cE) {
			this.date = cz;
			this.week = cB;
			this.station_train_code = cy;
			this.train_headers = cD;
			this.from_station = cA;
			this.start_time = cC;
			this.to_station = cF;
			this.arrive_time = cE
		};
		var co = new cu(cp, cm, cn, cw, cx, cs, cq, cv);
		cr.push(co);
		var ct = $("#autoSubTicketTitTemplate").html();
		$.templates({
			leftTableTemplate: ct
		});
		$("#autosubmit_check_ticket_tit").html($.render.leftTableTemplate(cr))
	}

	function m(cy) {
		if (aY) {
			clearInterval(aY)
		}
		var cn = "";
		var co = "";
		var ct = "";
		var cp = "";
		if ($("#sf2").is(":checked")) {
			ct = "3";
			cp = "学生票"
		}
		tickets_info = new Array();
		var cz = cy[1];
		var cs = cy[2];
		var cr = 0;
		var cq = passengerChecked.length;
		for (var cu = 0; cu < cs.length; cu++) {
			var cw = 0;
			if (cs[cu].toLowerCase() == "yyrw") {
				var cm = cz.queryLeftNewDTO["seat_types"];
				if (cs[cu].toLowerCase() == "yyrw" && cm.indexOf("A") > -1) {
					cw = cz.queryLeftNewDTO["gr_num"]
				}
			} else {
				cw = cz.queryLeftNewDTO[cs[cu].toLowerCase() + "_num"]
			}
			if (cw == "--" || cw == "无") {
				cw = 0
			} else {
				if (cw == "有") {
					cw = 20
				} else {
					cw = Number(cw)
				}
			}
			if (cr >= cq) {
				break
			}
			var cx = cs[cu];
			cn = av(cx);
			co = J(cx);
			for (var cv = 0; cv < cw; cv++) {
				if (cr >= cq) {
					break
				}
				ct = passengerChecked[cv].passenger_type;
				if (!ct || "" == ct) {
					ct = "1"
				}
				if (ct == "1") {
					cp = "成人票"
				} else {
					if (ct == "2") {
						cp = "儿童票"
					} else {
						if (ct == "3") {
							cp = "学生票"
						} else {
							if (ct == "4") {
								cp = "残军票"
							}
						}
					}
				}
				tickets_info.push(new a9("sdAdd_" + am(), cn, co, ct, cp, passengerChecked[cr].passenger_name, passengerChecked[cr].passenger_id_type_code, passengerChecked[cr].passenger_id_type_name, passengerChecked[cr].passenger_id_no, passengerChecked[cr].mobile_no));
				cr++
			}
		}
	}

	function cg(cn) {
		var cm;
		if ("X" == canChooseBeds) {
			$("#bed_show").html("<span style='background:url(../resources/images/icon_new.png) right center no-repeat; padding-right:30px; cursor: pointer;' title='欢迎使用12306选铺功能'>铺别</span>");
			cm = $("#autoSubCheckTicketInfoTemplate_chooseBeds").html().replace("<!--", "").replace("-->", "");
			$("#bed_show").show()
		} else {
			$("#bed_show").hide();
			cm = $("#autoSubCheckTicketInfoTemplate").html()
		}
		$.templates({
			leftTableTemplate: cm
		});
		$("#autosubmit_check_ticketInfo").html($.render.leftTableTemplate(cn))
	}

	function j() {
		var cp = K.queryLeftNewDTO.yz_num;
		var cm = K.queryLeftNewDTO.rz_num;
		var ct = K.queryLeftNewDTO.yw_num;
		var cr = K.queryLeftNewDTO.rw_num;
		var cs = K.queryLeftNewDTO.gr_num;
		var cq = K.queryLeftNewDTO.ze_num;
		var cv = K.queryLeftNewDTO.zy_num;
		var cw = K.queryLeftNewDTO.tz_num;
		var cn = K.queryLeftNewDTO.swz_num;
		var cu = K.queryLeftNewDTO.wz_num;
		var co = "";
		if (cp != "--") {
			co = "YZ";
			return co
		}
		if (cq != "--") {
			co = "ZE";
			return co
		}
		if (ct != "--") {
			co = "YW";
			return co
		}
		if (cv != "--") {
			co = "ZY";
			return co
		}
		if (cm != "--") {
			co = "RZ";
			return co
		}
		if (cr != "--") {
			co = "RW";
			return co
		}
		if (cw != "--") {
			co = "TZ";
			return co
		}
		if (cs != "--") {
			co = "GR";
			return co
		}
		if (cn != "--") {
			co = "SWZ";
			return co
		}
		if (cu != "--") {
			co = "WZ";
			return co
		}
	}

	function J(cn) {
		var cm = "";
		if (cn == "ZY") {
			cm = "一等座"
		}
		if (cn == "ZE") {
			cm = "二等座"
		}
		if (cn == "SWZ") {
			cm = "商务座"
		}
		if (cn == "TZ") {
			cm = "特等座"
		}
		if (cn == "YZ") {
			cm = "硬座"
		}
		if (cn == "RZ") {
			cm = "软座"
		}
		if (cn == "YW") {
			cm = "硬卧"
		}
		if (cn == "RW") {
			cm = "软卧"
		}
		if (cn == "GR") {
			cm = "高级软卧"
		}
		if (cn == "SRRB") {
			cm = "动卧"
		}
		if (cn == "YYRW") {
			cm = "高级动卧"
		}
		if (cn == "WZ") {
			cm = "无座"
		}
		return cm
	}

	function av(cn) {
		var cm = "";
		if (cn == "ZY") {
			cm = "M"
		}
		if (cn == "ZE") {
			cm = "O"
		}
		if (cn == "SWZ") {
			cm = "9"
		}
		if (cn == "TZ") {
			cm = "P"
		}
		if (cn == "YZ") {
			cm = "1"
		}
		if (cn == "RZ") {
			cm = "2"
		}
		if (cn == "YW") {
			cm = "3"
		}
		if (cn == "RW") {
			cm = "4"
		}
		if (cn == "GR") {
			cm = "6"
		}
		if (cn == "WZ") {
			cm = "WZ"
		}
		if (cn == "SRRB") {
			cm = "F"
		}
		if (cn == "YYRW") {
			cm = "A"
		}
		return cm
	}

	function a9(ct, co, cp, cr, cq, cn, cv, cu, cs, cm) {
		this.only_id = ct, this.seat_type = co;
		this.seat_type_name = cp;
		this.ticket_type = cr, this.ticket_type_name = cq;
		this.name = cn;
		this.id_type = cv;
		this.id_type_name = cu;
		this.id_no = cs;
		this.phone_no = cm;
		this.toString = function() {
			return this.name + "_" + this.id_type + "_" + this.id_no + "_" + this.phone_no
		}
	}

	function am() {
		if (tickets_info.length < 1) {
			return tickets_info.length
		} else {
			var co = 0;
			for (var cn = 0; cn < tickets_info.length; cn++) {
				var cm = Number(tickets_info[cn].only_id.split("_")[1]);
				if (cm > co) {
					co = cm
				}
			}
			return co + 1
		}
	}

	function aX() {
		bJ = [];
		W = [];
		aC = [];
		tickets_info = [];
		bO = [];
		bY = [];
		K = "";
		isAsync = "";
		location_code = "";
		md5Str = "";
		leftTicketStr = ""
	}
	getpassengerTicketsForAutoSubmit = function() {
		var cn = "";
		for (var cs = 0; cs < tickets_info.length; cs++) {
			var ct = "";
			if ("WZ" == tickets_info[cs].seat_type) {
				ct = av(j())
			} else {
				ct = tickets_info[cs].seat_type
			}
			var cq = $("#autosubmit_check_ticketInfo").find("select[id^=ticketype_]");
			var cu = "0";
			if (cq && cq.length > 0) {
				var cm = tickets_info[cs].seat_type + "#" + tickets_info[cs].ticket_type + "#" + tickets_info[cs].name + "#" + tickets_info[cs].id_no;
				for (var cr = 0, cx = cq.length; cr < cx; cr++) {
					var cv = cq.eq(cr);
					var co = cv.val().split("_")[0];
					var cp = cv.val().split("_")[1];
					if (cm == co) {
						cu = cp
					}
				}
			}
			var cw = ct + "," + cu + "," + tickets_info[cs].ticket_type + "," + tickets_info[cs].name + "," + tickets_info[cs].id_type + "," + tickets_info[cs].id_no + "," + (tickets_info[cs].phone_no == null ? "" : tickets_info[cs].phone_no) + ",N";
			cn += cw + "_"
		}
		return cn.substring(0, cn.length - 1)
	};
	getOldPassengersForAutoSubmit = function() {
		var co = "";
		for (var cn = 0; cn < passengerChecked.length; cn++) {
			var cm = passengerChecked[cn].passenger_name + "," + passengerChecked[cn].passenger_id_type_code + "," + passengerChecked[cn].passenger_id_no + "," + passengerChecked[cn].passenger_type;
			co += cm + "_"
		}
		return co
	};
	var aM = false;

	function bq(cm, cn) {
		var cr = "";
		var co = $("#train_date").val().split("-");
		var cp = new Date();
		cp.setFullYear(co[0], co[1] - 1, co[2]);
		if (isAsync == ticket_submit_order.request_flag.isAsync && leftTicketStr != "") {
			var cq = null;
			if (tickets_info[0].seat_type == "WZ") {
				if (K.queryLeftNewDTO.yz_num != "--") {
					tickets_info[0].seat_type = "1";
					aM = true;
					tickets_info[0].seat_type_name = "硬座"
				} else {
					if (K.queryLeftNewDTO.ze_num != "--") {
						tickets_info[0].seat_type = "O";
						aM = true;
						tickets_info[0].seat_type_name = "二等座"
					}
				}
			}
			$.ajax({
				url: ctx + "confirmPassenger/getQueueCountAsync",
				type: "post",
				async: false,
				data: {
					train_date: cp.toString(),
					train_no: K.queryLeftNewDTO.train_no,
					stationTrainCode: K.queryLeftNewDTO.station_train_code,
					seatType: tickets_info[0].seat_type,
					fromStationTelecode: K.queryLeftNewDTO.from_station_telecode,
					toStationTelecode: K.queryLeftNewDTO.to_station_telecode,
					leftTicket: leftTicketStr,
					purpose_codes: cm,
					isCheckOrderInfo: cn
				},
				dataType: "json",
				success: function(cu) {
					if (cu.status) {
						if (cu.data.isRelogin == "Y") {
							window.location.href = ctx + "login/init?random=" + new Date().getTime()
						}
						var cv = null;
						var ct = tickets_info[0].seat_type;
						cv = cu.data.ticket.split(",");
						cr = "本次列车，" + (tickets_info[0].seat_type_name).split("（")[0] + "余票";
						if (parseInt(cv[0]) >= 0) {
							cr += "<strong>" + cv[0] + "</strong>张"
						} else {
							cr += cv[0]
						}
						var cs = false;
						if (cv.length > 1) {
							cr += ",无座余票";
							if (parseInt(cv[1]) >= 0) {
								cr += "<strong>" + cv[1] + "</strong>张"
							} else {
								cr += cv[1]
							}
							cs = true
						}
						cr += "。";
						if (cu.data.op_2 == "true") {
							if ((aM && !cs) || !aM) {
								aO = false;
								M();
								return
							}
							cr += '<font color="red">目前排队人数已经超过余票张数，请您选择其他席别或车次。</font>'
						} else {
							if (cu.data.countT > 0) {
								cr += '目前排队人数<font color="red">' + cu.data.countT + "</font>人，";
								if (if_show_pass_code_login == "Y") {
									cr += "<br/>请确认以上信息是否正确，点击“确认”后，系统将为您分配席位。"
								}
							}
						}
						var cw = $("#sy_ticket_num_id");
						if (cw != null) {
							cw.html(cr)
						}
						bU()
					}
				},
				error: function(cs, cu, ct) {
					return
				}
			})
		} else {
			bU()
		}
	}

	function bs(cn, cm) {
		rt = "";
		seat_1 = -1;
		seat_2 = -1;
		i = 0;
		while (i < cn.length) {
			s = cn.substr(i, 10);
			c_seat = s.substr(0, 1);
			if (c_seat == cm) {
				count = s.substr(6, 4);
				while (count.length > 1 && count.substr(0, 1) == "0") {
					count = count.substr(1, count.length)
				}
				count = parseInt(count);
				if (count < 3000) {
					seat_1 = count
				} else {
					seat_2 = (count - 3000)
				}
			}
			i = i + 10
		}
		if (seat_1 > -1) {
			rt += seat_1
		}
		if (seat_2 > -1) {
			rt += "," + seat_2
		}
		return rt
	}

	function ck() {
		$.ajax({
			url: ctx + "confirmPassenger/confirmSingle",
			type: "post",
			data: {
				passengerTicketStr: getpassengerTicketsForAutoSubmit(),
				oldPassengerStr: getOldPassengersForAutoSubmit(),
				tour_flag: "dc",
				randCode: $("#randCode_other").val(),
				purpose_codes: ch(),
				key_check_isChange: md5Str,
				train_location: location_code,
				choose_seats: bD(),
				seatDetailType: aL()
			},
			dataType: "json",
			async: true,
			success: function(cm) {
				if (cm.status) {
					if (cm.data.submitStatus) {
						otsRedirect("post", ctx + "payOrder/init?random=" + new Date().getTime(), {})
					} else {
						ac("出票失败!", false, "原因： " + cm.data.errMsg + '<a  id="xg_close_win_id">点击修改</a>', true, "lose");
						$("#xg_close_win_id").click(function() {
							af("transforNotice_id", true);
							$("#i-ok").css("display", "none")
						})
					}
				} else {
					ac("订票失败!", true, "很抱歉！请关闭窗口重新预定车票", true, "lose")
				}
			},
			error: function(cm, co, cn) {
				ac("订票失败!", true, "很抱歉！网络忙，请关闭窗口稍后再试。", true, "lose");
				return
			}
		})
	}

	function q() {
		$.ajax({
			url: ctx + "confirmPassenger/confirmSingleForQueueAsys",
			type: "post",
			data: {
				passengerTicketStr: getpassengerTicketsForAutoSubmit(),
				oldPassengerStr: getOldPassengersForAutoSubmit(),
				randCode: $("#randCode_other").val(),
				purpose_codes: ch(),
				key_check_isChange: md5Str,
				leftTicketStr: leftTicketStr,
				train_location: location_code,
				choose_seats: bD(),
				seatDetailType: aL()
			},
			dataType: "json",
			async: true,
			success: function(cm) {
				$("#i-ok").css("display", "none");
				$("#i-ok2").css("display", "none");
				$("#c_error2").html("");
				$("#c_error2").removeClass("error");
				$("#randCode2").val("");
				if (cm.status) {
					if (!cm.data.submitStatus) {
						ac("出票失败!", false, "原因： " + cm.data.errMsg + '<a id="xg_close_win_id" >点击修改</a>', true, "lose");
						$("#xg_close_win_id").click(function() {
							af("transforNotice_id", true)
						});
						if (cm.data.errMsg.indexOf("余票不足") >= 0) {
							jPlayer("stop");
							$("#qr_closeTranforDialog_id").click();
							$("#query_ticket").click()
						}
					} else {
						var cn = new OrderQueueWaitTime("dc", an, r);
						cn.start(queryOrderWaitTimeInterval)
					}
				} else {
					ac("订票失败!", true, "很抱歉！请关闭窗口重新预定车票", true, "lose")
				}
			},
			error: function(cm, co, cn) {
				ac("订票失败!", true, "很抱歉！网络忙，请关闭窗口稍后再试。", true, "lose");
				return
			}
		})
	}

	function an(cm, co, cn) {
		if (co <= 5) {
			ac("订单已经提交，系统正在处理中，请稍等。", false, "", false, "work")
		} else {
			if (co > 30 * 60) {
				ac("订单已经提交，预计等待时间超过30分钟，请耐心等待。", false, "", false, "queue")
			} else {
				ac("订单已经提交，最新预估等待时间" + cn + "，请耐心等待。", false, "", false, "queue")
			}
		}
	}

	function r(cm, co, cn) {
		if (co == -1 || co == -100) {
			$.ajax({
				url: ctx + "confirmPassenger/resultOrderForDcQueue",
				data: {
					orderSequence_no: cn.orderId
				},
				type: "POST",
				dataType: "json",
				success: function(cp) {
					if (cp.status) {
						if (cp.data.submitStatus) {
							otsRedirect("post", ctx + "/payOrder/init?random=" + new Date().getTime(), {})
						} else {
							ac("下单成功", false, "", false, "win")
						}
					} else {
						ac("下单成功。", false, "", false, "win")
					}
				},
				error: function(cp, cr, cq) {
					ac("下单成功。", false, "", false, "win")
				}
			})
		} else {
			bH(co, cn)
		}
	}

	function bH(cm, cn) {
		if (cn.name && cn.card && cn.tel) {
			af("transforNotice_id", true);
			$("#608_check_msg").html(cn.msg);
			dhtmlx.createWin({
				winId: "608_check",
				closeWinId: ["608_check_close", "608_check_cancel"],
				okId: "608_check_ok",
				okCallBack: function() {
					$("#608_name").html(cn.name);
					$("#608_card").html(cn.card);
					$("#608_tel").html(cn.tel);
					$("#ticketInfo").html(cn.ticketInfo);
					dhtmlx.createWin({
						winId: "608_complain",
						closeWinId: ["608_complain_close", "608_complain_cancel"],
						okId: "608_complain_ok",
						okCallBack: function() {
							var co = dhtmlx.modalbox({
								targSrc: '<div><img src="' + ctx + 'resources/images/loading.gif"></img></div>',
								callback: function() {}
							});
							$.ajax({
								url: ctx + "confirmPassenger/report",
								type: "post",
								async: false,
								success: function(cp) {
									dhtmlx.modalbox.hide(co);
									if (cp.data == "Y") {
										dhtmlx.alert({
											title: "提示",
											ok: messages["button.ok"],
											text: "举报成功",
											type: "alert-info"
										})
									} else {
										dhtmlx.alert({
											title: "提示",
											ok: messages["button.ok"],
											text: "举报失败",
											type: "alert-error"
										})
									}
									$("#i-okmypasscode1").hide();
									if (ifAlertCode) {
										refreshImg("passenger", "randp", "other")
									}
								},
								error: function(cp, cr, cq) {
									dhtmlx.modalbox.hide(co)
								}
							})
						},
						checkConfirm: function() {
							return true
						}
					});
					$("#608_complain").css("top", "200px")
				},
				checkConfirm: function() {
					return true
				},
				callback: function() {
					$("#i-okmypasscode1").hide();
					if (ifAlertCode) {
						refreshImg("passenger", "randp", "other")
					}
				}
			});
			$("#608_check").css("top", "200px");
			return
		}
		if (cm == -1) {
			return
		} else {
			if (cm == -2) {
				if (cn.errorcode == 0) {
					ac("订票失败!", true, "原因： " + cn.msg, true, "lose")
				} else {
					ac("订票失败!", true, "原因： " + cn.msg, true, "lose")
				}
				if (cn.msg.indexOf("没有足够的票") > -1) {
					jPlayer("stop");
					$("#qr_closeTranforDialog_id").click();
					$("#query_ticket").click()
				}
			} else {
				if (cm == -3) {
					ac("哎呀,订票失败!", true, "订单已撤销", true, "lose")
				} else {
					window.location.href = ctx + "queryOrder/initNoComplete?random=" + new Date().getTime()
				}
			}
		}
	}

	function R() {
		cf = new dhtmlXWindows();
		cf.enableAutoViewport(true);
		cf.setSkin("dhx_terrace");
		cf.setImagePath(ctx + "resources/js/rich/windows/imgs/");
		af = function(cq, cp) {
			unLoadGrayBackground();
			if (cf.isWindow(cq + "_")) {
				cf.window(cq + "_").setModal(false);
				cf.window(cq + "_").hide()
			}
		};
		ac = function(cw, ct, cq, cp, cs) {
			var cv = '<div class="tit">' + (ct ? '<span class="colorC">' + cw + "</span>" : cw) + "</div>";
			var cr = "<P>" + cq + "</p>";
			var cu = ct ? '<p>请点击[<a href="' + ctx + 'queryOrder/init"><strong>我的12306</strong></a>]办理其他业务。您也可以点击[<a href="' + ctx + 'leftTicket/init"><strong>预订车票</strong></a>]，重新规划您的旅程。</p>' : '<P>查看订单处理情况，请点击“<a href="' + ctx + 'queryOrder/initNoComplete">未完成订单</a>”</P>';
			$("#iamge_status_id").removeClass().addClass("icon i-" + cs);
			if (cp) {
				$("#up-box-hd_id").html("提示<a id='closeTranforDialog_id' href='#nogo'>关闭</a>");
				cu = "";
				$("#lay-btn_id").html("<a href='#nogo' id='qr_closeTranforDialog_id'  class='btn92s'>确认</a>")
			} else {
				$("#up-box-hd_id").html("提示");
				$("#lay-btn_id").html("")
			}
			$("#orderResultInfo_id").html(cv + (cq == "" || cq == null || cq == "undefined" || cq == undefined ? "" : cr) + cu);
			cm("transforNotice_id");
			if (cp) {
				$("#closeTranforDialog_id").click(function() {
					af("transforNotice_id", true)
				});
				$("#qr_closeTranforDialog_id").click(function() {
					af("transforNotice_id", true);
					$("#i-ok").css("display", "none")
				})
			}
		};

		function cm(ct) {
			af(ct, false);
			if ("checkticketinfo_id" == ct) {
				var cr = ticketInfoForPassengerForm.queryLeftNewDetailDTO;
				if (cr.to_station_telecode == ticket_submit_order.special_areas.lso || cr.to_station_telecode == ticket_submit_order.special_areas.dao || cr.to_station_telecode == ticket_submit_order.special_areas.ado || cr.to_station_telecode == ticket_submit_order.special_areas.nqo || cr.to_station_telecode == ticket_submit_order.special_areas.tho) {
					if (cn()) {
						$("#notice_1_id").html("1.系统将随机为您申请席位，暂不支持自选席位。");
						$("#notice_2_id").html("2.根据现行规定，外国人在购买进西藏火车票时，须出示西藏自治区外事办公室或旅游局、商务厅的批准函（电），或者出示中国内地司局级接待单位出具的、已征得自治区上述部门同意的证明信函。台湾同胞赴藏从事旅游、商务活动，须事先向西藏自治区旅游局或商务厅提出申请，购买进藏火车票时须出示有关批准函。");
						if (co()) {
							$("#notice_3_id").html("3.按现行规定，学生票购票区间必须与学生证上的乘车区间一致，否则车站将不予换票。")
						} else {
							$("#notice_3_id").html("")
						}
					}
				} else {
					$("#notice_1_id").html("1.系统将随机为您申请席位，暂不支持自选席位。");
					if (co()) {
						$("#notice_3_id").html("2.按现行规定，学生票购票区间必须与学生证上的乘车区间一致，否则车站将不予换票。")
					} else {
						$("#notice_3_id").html("")
					}
				}
			}
			var cq = a2(ct);
			var cp = $(window).width() / 2 - 300;
			var cs = ce() + ($(window).height() / 2 - 200);
			cq.setDimension($("#content_" + ct).width(), $("#content_" + ct).height() + 10);
			$(".dhtmlx_window_active").height($("#content_" + ct).height());
			$(".dhtmlx_window_active").css({
				left: cp + "px",
				top: cs + "px"
			})
		}

		function co() {
			for (var cq = 0; cq < limit_tickets.length; cq++) {
				var cp = limit_tickets[cq];
				if (cp.ticket_type == ticket_submit_order.ticket_type.student) {
					return true
				}
			}
			return false
		}

		function cn() {
			for (var cq = 0; cq < limit_tickets.length; cq++) {
				var cp = limit_tickets[cq];
				if ((ticketInfoForPassengerForm.tour_flag == ticket_submit_order.tour_flag.fc || ticketInfoForPassengerForm.tour_flag == ticket_submit_order.tour_flag.gc) && cp.save_status != "" && (cp.id_type == ticket_submit_order.passenger_card_type.passport || cp.id_type == ticket_submit_order.passenger_card_type.work || cp.id_type == ticket_submit_order.passenger_card_type.taiwan)) {
					return true
				} else {
					if ((ticketInfoForPassengerForm.tour_flag == ticket_submit_order.tour_flag.wc || ticketInfoForPassengerForm.tour_flag == ticket_submit_order.tour_flag.dc) && (cp.id_type == ticket_submit_order.passenger_card_type.passport || cp.id_type == ticket_submit_order.passenger_card_type.work || cp.id_type == ticket_submit_order.passenger_card_type.taiwan)) {
						return true
					}
				}
			}
			return false
		}
	}

	function a2(cn) {
		var cm = cf.createWindow(cn + "_", 0, 0, 660, 100);
		cm.attachObject(cn);
		cm.clearIcon();
		cm.denyResize();
		cm.setModal(true);
		cm.center();
		cm.button("park").hide();
		cm.button("minmax1").hide();
		cm.hideHeader();
		return cm
	}

	function C(cn) {
		var cm = new Date();
		var co = cn.split("-");
		cm.setFullYear(parseInt(co[0]), parseInt(co[1] - 1, 10), parseInt(co[2], 10));
		if (co.length >= 6) {
			cm.setHours(co[3], co[4], co[5])
		}
		return cm
	}

	function aD(cm) {
		var cp = "",
			co = "";
		var cr = cm.replace(/-/g, "");
		if (cr.substring(4, 5) == "0") {
			cp = cr.substring(5, 6) + "月"
		} else {
			cp = cr.substring(4, 6) + "月"
		}
		if (cr.substring(6, 7) == "0") {
			co = cr.substring(7, 8) + "日"
		} else {
			co = cr.substring(6, 8) + "日"
		}
		var cn = new Date(Date.parse(cm.replace(/-/g, "/")));
		var cq = "日一二三四五六";
		return cp.concat(co).concat("&nbsp;&nbsp;").concat("周").concat(cq.charAt(cn.getDay()))
	}
	showTicketPrice = function(cq) {
		var cu = $(cq).parent("tr").children("td").children("div").children("div").children("span").attr("id");
		if (undefined == cu || cu == null || "undefined" == typeof(cu)) {
			cu = $(cq).attr("id")
		}
		$("#price_" + cr).hide();
		$("#tp-list-price").hide();
		$("#sleeper-price>span").css("cursor", "pointer");
		var cr = cu.split("_")[0];
		var cs = $("#price_" + cr).attr("datatran");
		var ct = cu.split("_")[1];
		var cp = cu.split("_")[2];
		var cv = cu.split("_")[3];
		var co = cu.split("_")[4];
		var cm = $("#WZ_" + cr).html();
		var cn = $("#QT_" + cr).html();
		if (co && ($("#ticket_" + cr + "_train>span>span").text() == "查看票价")) {
			if ($("#ticket_" + cr).attr("class") == "bgc") {
				$("#price_" + cr).addClass("bgc")
			}
			$.ajax({
				type: "get",
				isTakeParam: false,
				beforeSend: function(cw) {
					cw.setRequestHeader("If-Modified-Since", "0");
					cw.setRequestHeader("Cache-Control", "no-cache")
				},
				url: ctx + "leftTicket/queryTicketPriceFL",
				data: {
					train_no: cr,
					from_station_no: ct,
					to_station_no: cp,
					seat_types: co,
					train_date: train_tour_flag == "fc" ? $.trim($("#back_train_date").val()) : $.trim($("#train_date").val())
				},
				timeout: 1000,
				error: function(cw, cy, cx) {},
				success: function(cw) {}
			});
			$.ajax({
				type: "get",
				isTakeParam: false,
				beforeSend: function(cw) {
					cw.setRequestHeader("If-Modified-Since", "0");
					cw.setRequestHeader("Cache-Control", "no-cache")
				},
				url: ctx + "leftTicket/queryTicketPrice",
				data: {
					train_no: cr,
					from_station_no: ct,
					to_station_no: cp,
					seat_types: co,
					train_date: train_tour_flag == "fc" ? $.trim($("#back_train_date").val()) : $.trim($("#train_date").val())
				},
				success: function(cw) {
					if (cw.status) {
						$("#ticket_" + cr + "_train>span>span").html("收起票价");
						$("#ticket_" + cr + "_train>span>b").addClass("open");
						$("#ticket_" + cr + "_train>span>b").attr("title", "收起票价");
						if (cn == "--") {
							cw.data.MIN = ""
						}
						if (cm == "--") {
							cw.data.WZ = ""
						}
						$("#price_" + cr).html($.render.priceTableTemplate(cw.data));
						$("#price_" + cr).show();
						if (cs && c(cs)) {
							$("#price_" + cr).find("td").eq(0).html('<a class="ad-tlist-hot" href="javascript:void(0);">移动宾馆 免费晚餐 快捷舒适 准时正点</a>')
						} else {
							$("#price_" + cr).find("td").eq(0).html("")
						}
						if (cw.data.PM != "--") {
							$("#sleeper-price_" + cr).mouseover(function() {
								$("#tp-list-price_" + cr).show()
							});
							$("#sleeper-price_" + cr).mouseout(function() {
								$("#tp-list-price_" + cr).hide()
							})
						}
					}
				}
			})
		} else {
			$("#ticket_" + cr + "_train>span>span").html("查看票价");
			$("#ticket_" + cr + "_train>span>b").attr("title", "查看票价");
			$("#ticket_" + cr + "_train>span>b").removeClass();
			$("#price_" + cr).html("");
			$("#price_" + cr).hide()
		}
	};

	function bS(cm) {
		if (ay == "starttime") {
			return cm.sort(function(co, cn) {
				var cq = Number(co.queryLeftNewDTO.start_time.replace(":", ""));
				var cp = Number(cn.queryLeftNewDTO.start_time.replace(":", ""));
				if (cq > cp) {
					return a1 ? 1 : -1
				} else {
					return a1 ? -1 : 1
				}
			})
		} else {
			if (ay == "arrivedtime") {
				return cm.sort(function(co, cn) {
					var cq = Number(co.queryLeftNewDTO.arrive_time.replace(":", ""));
					var cp = Number(cn.queryLeftNewDTO.arrive_time.replace(":", ""));
					if (cq > cp) {
						return b1 ? 1 : -1
					} else {
						return b1 ? -1 : 1
					}
				})
			} else {
				if (ay == "lishi") {
					return cm.sort(function(co, cn) {
						var cq = Number(co.queryLeftNewDTO.lishi.replace(":", ""));
						var cp = Number(cn.queryLeftNewDTO.lishi.replace(":", ""));
						if (cq > cp) {
							return aW ? 1 : -1
						} else {
							return aW ? -1 : 1
						}
					})
				}
			}
		}
		return cm
	}

	function az() {
		$("#s_time").click(function() {
			if (a1) {
				$("#s_time").removeClass().addClass("b4");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				a1 = false;
				$("#other_span_starttime").removeClass().addClass("b4");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			} else {
				$("#s_time").removeClass().addClass("b3");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				a1 = true;
				$("#other_span_starttime").removeClass().addClass("b3");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			}
			ay = "starttime";
			aH()
		});
		$("#other_span_starttime").click(function() {
			if (a1) {
				$("#s_time").removeClass().addClass("b4");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				a1 = false;
				$("#other_span_starttime").removeClass().addClass("b4");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			} else {
				$("#s_time").removeClass().addClass("b3");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				a1 = true;
				$("#other_span_starttime").removeClass().addClass("b3");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			}
			ay = "starttime";
			aH()
		});
		$("#r_time").click(function() {
			if (b1) {
				$("#r_time").removeClass().addClass("b4");
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				b1 = false;
				$("#other_span_starttime").removeClass().addClass("b4");
				$("#other_span_endtime").removeClass().addClass("b2");
				$("#other_span_lishi").removeClass().addClass("b2")
			} else {
				$("#r_time").removeClass().addClass("b3");
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				b1 = true;
				$("#other_span_endtime").removeClass().addClass("b2");
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			}
			ay = "arrivedtime";
			aH()
		});
		$("#other_span_endtime").click(function() {
			if (b1) {
				$("#r_time").removeClass().addClass("b4");
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				b1 = false;
				$("#other_span_endtime").removeClass().addClass("b4");
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			} else {
				$("#r_time").removeClass().addClass("b3");
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				if ($("#l_s").attr("class") == "b4") {
					$("#l_s").removeClass().addClass("b2")
				} else {
					if ($("#l_s").attr("class") == "b3") {
						$("#l_s").removeClass().addClass("b1")
					}
				}
				b1 = true;
				$("#other_span_endtime").removeClass().addClass("b3");
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_lishi").attr("class") == "b4") {
					$("#other_span_lishi").removeClass().addClass("b2")
				} else {
					if ($("#other_span_lishi").attr("class") == "b3") {
						$("#other_span_lishi").removeClass().addClass("b1")
					}
				}
			}
			ay = "arrivedtime";
			aH()
		});
		$("#l_s").click(function() {
			if (aW) {
				$("#l_s").removeClass().addClass("b4");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				aW = false;
				$("#other_span_lishi").removeClass().addClass("b4");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
			} else {
				$("#l_s").removeClass().addClass("b3");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				aW = true;
				$("#other_span_lishi").removeClass().addClass("b3");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
			}
			ay = "lishi";
			aH()
		});
		$("#other_span_lishi").click(function() {
			if (aW) {
				$("#l_s").removeClass().addClass("b4");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				aW = false;
				$("#other_span_lishi").removeClass().addClass("b4");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
			} else {
				$("#l_s").removeClass().addClass("b3");
				if ($("#r_time").attr("class") == "b4") {
					$("#r_time").removeClass().addClass("b2")
				} else {
					if ($("#r_time").attr("class") == "b3") {
						$("#r_time").removeClass().addClass("b1")
					}
				}
				if ($("#s_time").attr("class") == "b4") {
					$("#s_time").removeClass().addClass("b2")
				} else {
					if ($("#s_time").attr("class") == "b3") {
						$("#s_time").removeClass().addClass("b1")
					}
				}
				aW = true;
				$("#other_span_lishi").removeClass().addClass("b3");
				if ($("#other_span_endtime").attr("class") == "b4") {
					$("#other_span_endtime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_endtime").attr("class") == "b3") {
						$("#other_span_endtime").removeClass().addClass("b1")
					}
				}
				if ($("#other_span_starttime").attr("class") == "b4") {
					$("#other_span_starttime").removeClass().addClass("b2")
				} else {
					if ($("#other_span_starttime").attr("class") == "b3") {
						$("#other_span_starttime").removeClass().addClass("b1")
					}
				}
			}
			ay = "lishi";
			aH()
		})
	}
	closeTrainStop = function() {
		over_flag = false;
		bZ = 0;
		$("#train_stop").hide();
		$("#train_table").html("")
	};
	hideTrainStop = function(cm) {
		over_flag = false;
		if (p) {
			clearTimeout(p)
		}
		p = window.setTimeout(function() {
			if (bZ != 1) {
				bZ = 0;
				$("#train_stop").hide();
				$("#train_table").html("")
			}
		}, 130)
	};
	checkHover = function(cn, cm) {
		if (getEvent(cn).type == "mouseover") {
			return !$.contains(cm, getEvent(cn).relatedTarget || getEvent(cn).fromElement) && !((getEvent(cn).relatedTarget || getEvent(cn).fromElement) === cm)
		} else {
			return !$.contains(cm, getEvent(cn).relatedTarget || getEvent(cn).toElement) && !((getEvent(cn).relatedTarget || getEvent(cn).toElement) === cm)
		}
	};
	getEvent = function(cm) {
		return cm || window.event
	};
	checkHover = function(cn, cm) {
		if (getEvent(cn).type == "mouseover") {
			return !$.contains(cm, getEvent(cn).relatedTarget || getEvent(cn).fromElement) && !((getEvent(cn).relatedTarget || getEvent(cn).fromElement) === cm)
		} else {
			return !$.contains(cm, getEvent(cn).relatedTarget || getEvent(cn).toElement) && !((getEvent(cn).relatedTarget || getEvent(cn).toElement) === cm)
		}
	};
	getEvent = function(cm) {
		return cm || window.event
	};

	function bB(co, cm) {
		for (var cn = 0; cn < cm.length; cn++) {
			if (cm[cn].key == co) {
				return true
			}
		}
		return false
	}

	function bl(cq) {
		var cv = function(cw) {
			this.value = cw
		};
		var cr = new Array();
		var cn = new Array();
		var cp = {};
		var cm = {};
		$("#cc_from_station_name_all>ul").html("");
		$("#cc_to_station_name_all>ul").html("");
		var co;
		var cu;
		var ct;
		for (var cs = 0; cs < cq.length; cs++) {
			co = cq[cs].queryLeftNewDTO.from_station_name;
			cu = cq[cs].queryLeftNewDTO.to_station_name;
			ct = cq[cs];
			if (!cp[co]) {
				cr.push(new cv(co));
				cp[co] = true
			}
			if (!cm[cu]) {
				cn.push(new cv(cu));
				cm[cu] = true
			}
		}
		$("#to_station_ul").html($.render.toStationNameTableTemplate(cn));
		$("#from_station_ul").html($.render.stationNameTableTemplate(cr));
		$("#sear-sel-bd input[name='cc_from_station']").click(function() {
			k(bA, "cc_from_station_" + $(this).val());
			var cw = $("input[name='cc_from_station']");
			var cx = $("input[name='cc_from_station']:checked");
			if ($(this).is(":checked")) {
				if (cw && cx && cx.length == cw.length) {
					$("#from_station_name_all").removeClass().addClass("btn-all")
				} else {
					$("#from_station_name_all").removeClass().addClass("btn-all btn-all-sel")
				}
			} else {
				if (cw && cx && cx.length == 0) {
					$("#from_station_name_all").removeClass().addClass("btn-all")
				} else {
					$("#from_station_name_all").removeClass().addClass("btn-all btn-all-sel")
				}
			}
			aH()
		});
		$("#sear-sel-bd input[name='cc_to_station']").click(function() {
			k(bo, "cc_to_station_" + $(this).val());
			var cw = $("input[name='cc_to_station']");
			var cx = $("input[name='cc_to_station']:checked");
			if ($(this).is(":checked")) {
				if (cw && cx && cx.length == cw.length) {
					$("#to_station_name_all").removeClass().addClass("btn-all")
				} else {
					$("#to_station_name_all").removeClass().addClass("btn-all btn-all-sel")
				}
			} else {
				if (cw && cx && cx.length == 0) {
					$("#to_station_name_all").removeClass().addClass("btn-all")
				} else {
					$("#to_station_name_all").removeClass().addClass("btn-all btn-all-sel")
				}
			}
			aH()
		})
	}
	submitOrderRequest = function(cn, cm) {
		$.ajax({
			type: "post",
			url: ctx + "login/checkUser",
			data: {},
			beforeSend: function(co) {
				co.setRequestHeader("If-Modified-Since", "0");
				co.setRequestHeader("Cache-Control", "no-cache")
			},
			success: function(co) {
				var cq;
				checkusermdId = co.attributes;
				if (co.data.flag) {
					if (train_tour_flag == "fc") {
						cq = $("#back_train_date").val()
					} else {
						cq = $("#train_date").val()
					}
					if (x == "0X00") {
						var cp = false;
						for (i = (studentComPerArr.length - 1); i >= 0; i = i - 2) {
							if (C(studentComPerArr[i - 1]) <= C(cq) && C(studentComPerArr[i]) >= C(cq)) {
								cp = true;
								break
							}
						}
						if (!cp) {
							b("学生票的乘车时间为每年的暑假6月1日至9月30日、寒假12月1日至3月31日，目前不办理学生票业务。");
							return
						}
					}
					S(cn, cm)
				} else {
					bv();
					$("#floatTable").hide();
					a = $(window).scrollTop();
					aa(cn, cm)
				}
			}
		})
	};

	function S(cz, cs) {
		var cm = "";
		if ($("#dc").is(":checked")) {
			cm = "dc"
		} else {
			cm = "wc"
		}
		if (train_tour_flag == "fc") {
			cm = "fc";
			var cp = cs.split(":");
			var co = $("#back_train_date").val() + "-" + cp[0] + "-" + cp[1] + "-00";
			try {
				if (roundReferTime) {
					if (C(roundReferTime) >= C(co)) {
						b("您预订的往程车票到站时间为" + C(roundReferTime).format("yyyy年MM月dd日 hh时mm分") + "，返回日期不能早于此时间");
						return
					}
				}
			} catch (cu) {}
		}
		if (train_tour_flag == "gc") {
			cm = "gc"
		}
		if ("undefined" == typeof(submitForm)) {
			var cq = "secretStr=" + cz + "&train_date=" + $("#train_date").val() + "&back_train_date=" + $("#back_train_date").val() + "&tour_flag=" + cm + "&purpose_codes=" + ch() + "&query_from_station_name=" + $("#fromStationText").val() + "&query_to_station_name=" + $("#toStationText").val() + "&" + cx
		} else {
			var cn = submitForm();
			var cy = cn.split(":::");
			var ct = cy[0].split(",-,")[0];
			var cw = cy[0].split(",-,")[1];
			var cr = cy[1].split(",-,")[0];
			var cv = cy[1].split(",-,")[1];
			var cq = escape(ct) + "=" + escape(cw) + "&" + cr + "=" + cv + "&secretStr=" + cz + "&train_date=" + $("#train_date").val() + "&back_train_date=" + $("#back_train_date").val() + "&tour_flag=" + cm + "&purpose_codes=" + ch() + "&query_from_station_name=" + $("#fromStationText").val() + "&query_to_station_name=" + $("#toStationText").val() + "&" + cx
		}
		var cx = checkusermdId != undefined ? "&_json_att=" + encodeURIComponent(checkusermdId) : "";
		$.ajax({
			type: "post",
			url: ctx + "leftTicket/submitOrderRequest",
			data: cq,
			async: false,
			success: function(cA) {
				if (cA.status) {
					if (cA.data == "Y") {
						dhtmlx.alert({
							title: "温馨提示",
							ok: "确定",
							text: "您选择的列车距开车时间很近了，请确保有足够的时间抵达车站，并办理换取纸质车票、安全检查、实名制验证及检票等手续，以免耽误您的旅行。",
							type: "alert-warn",
							callback: function() {
								aU(cm, train_tour_flag)
							}
						})
					} else {
						aU(cm, train_tour_flag)
					}
				}
			}
		})
	}

	function aU(cn, cm) {
		if (cm != null) {
			if (cm == "fc") {
				otsRedirect("post", ctx + "confirmPassenger/initFc", {});
				return
			}
			if (cm == "gc") {
				otsRedirect("post", ctx + "confirmPassenger/initGc", {});
				return
			}
		}
		if (cn == "dc") {
			otsRedirect("post", ctx + "confirmPassenger/initDc", {});
			return
		} else {
			otsRedirect("post", ctx + "confirmPassenger/initWc", {})
		}
	}
	var ci = $("#fromStation").val();
	var bd = $("#toStation").val();
	var bW = $.trim($("#train_date").val());
	a6 = ci + bd + bW;
	$("#add-train").click(function() {
		if ($("#fromStationText").val() == "简拼/全拼/汉字") {
			dhtmlx.alert({
				title: "输入车次",
				ok: "确定",
				text: "请填写出发地！",
				type: "alert-error"
			});
			return
		}
		if ($("#toStationText").val() == "简拼/全拼/汉字") {
			dhtmlx.alert({
				title: "输入车次",
				ok: "确定",
				text: "请填写目的地！",
				type: "alert-error"
			});
			return
		}
		var cp = $('#prior_train span[name="prior_train-span"]').length;
		var cq = $.trim($("#inp-train").val()).toUpperCase();
		if (cq.length == 0 || cq == "请输入") {
			dhtmlx.alert({
				title: "输入车次",
				ok: "确定",
				text: "请输入车次",
				type: "alert-error",
				callback: function() {
					$("#inp-train").val("");
					$("#inp-train").focus()
				}
			})
		} else {
			if (cp < 6) {
				var cn = /^[a-zA-Z0-9]+$/;
				var co = /^[0-9]+$/;
				if (!cn.test(cq)) {
					dhtmlx.alert({
						title: "输入车次",
						ok: "确定",
						text: "车次格式输入错误！",
						type: "alert-error",
						callback: function() {
							ccInputSelected = true;
							$("#inp-train").select()
						}
					})
				} else {
					if (co.test(cq) && cq.length > 4) {
						dhtmlx.alert({
							title: "输入车次",
							ok: "确定",
							text: "车次格式输入错误！",
							type: "alert-error",
							callback: function() {
								ccInputSelected = true;
								$("#inp-train").select()
							}
						})
					} else {
						if (cq.length < 2) {
							dhtmlx.alert({
								title: "输入车次",
								ok: "确定",
								text: "车次格式输入错误！",
								type: "alert-error",
								callback: function() {
									ccInputSelected = true;
									$("#inp-train").select()
								}
							})
						} else {
							if ($.inArray(cq, ccSelected) < 0) {
								var cm = "<span name='prior_train-span' class='sel-box w80'>" + cq + "<a class='close' href='javascript:' onclick='$.removeSel(this,\"" + cq + "\",4)'></a></span>";
								$("#prior_train").append(cm);
								ccSelected.push(cq);
								$("#inp-train").val("")
							} else {
								dhtmlx.alert({
									title: "输入车次",
									ok: "确定",
									text: "此车次已经添加过！",
									type: "alert-error",
									callback: function() {
										ccInputSelected = true;
										$("#inp-train").select()
									}
								})
							}
						}
					}
				}
			} else {
				dhtmlx.alert({
					title: "输入车次",
					ok: "确定",
					text: "最多添加5个优先车次",
					type: "alert-error"
				});
				$("#inp-train").val("")
			}
		}
	});

	function ch() {
		if ($("#sf2").is(":checked")) {
			return "0X00"
		} else {
			return "ADULT"
		}
	}
	$("#yxtrain_close").click(function(cm) {
		$("#yxtraindiv").hide()
	});
	$("#yxtrain_a_close").click(function(cm) {
		$("#yxtraininput").val("");
		$("#yxtraininput").trigger("keyup")
	});
	$("#passenger_a_close").click(function(cm) {
		$("#searchPassenger").val("");
		$("#searchPassenger").trigger("keyup")
	});
	$("#yxtraininput").bind("keyup", function() {
		var cn = $(this).val().toUpperCase();
		var cm = $("#yxtrain_code").height();
		if (u(cn, 0)) {
			cl(1)
		} else {
			cl(3)
		}
		$("#yxtrain_code").css("height", cm)
	});

	function cl(cm) {
		$("#yxtrain_loading").hide();
		$("#yxtrain_code").hide();
		$("#yxTrain_page").hide();
		$("#yxtrain_empty").hide();
		if (1 == cm) {
			$("#yxtrain_code").show();
			$("#yxTrain_page").show()
		} else {
			if (2 == cm) {
				$("#yxtrain_loading").show()
			} else {
				if (3 == cm) {
					$("#yxtrain_empty").show()
				}
			}
		}
	}

	function u(cA, cm) {
		cA = cA.toUpperCase();
		var cw = [];
		var cB = $("#prior_train span:gt(1)");
		if (cB && cB.length > 0) {
			for (var cp = 0; cp < cB.length; cp++) {
				cw.push(cB[cp].innerText)
			}
		}
		var cz = [];
		var cv = [];
		if (trainListForIE && trainListForIE.length > 0) {
			for (var cn = 0; cn < trainListForIE.length; cn++) {
				cz.push(trainListForIE[cn]);
				cv.push(trainListForIE[cn])
			}
		}
		if (cA) {
			for (var cp = 0; cp < cv.length; cp++) {
				var cu = cv[cp].substring(0, cv[cp].indexOf("("));
				if (cu.indexOf(cA) <= -1) {
					cz.splice($.inArray(cv[cp], cz), 1)
				}
			}
		}
		if (cz && cz.length > 0) {
			var cr = "";
			for (var cp = 0; cp < cz.length; cp++) {
				var cu = cz[cp];
				var cq = cu.indexOf("(") > -1 ? cu.substring(0, cu.indexOf("(")) : cu;
				var cx = cp >= yxTrainPageSize * (cm) && cp < yxTrainPageSize * (cm + 1);
				if (cx) {
					if (cq.indexOf(cA) > -1) {
						var ct = cu.indexOf(cA);
						var cs = cu.substring(0, ct);
						var cy = cu.substring(ct + cA.length, cu.indexOf("("));
						var co = cu.substring(cu.indexOf("("));
						if (cw && cw.length > 0 && $.inArray(cq, cw) > -1) {
							cr += '<li style="width: 140px;" traincode=' + cq + ' name="yxtrainli" class="cur"><span style="font-size:15px;">' + cs + '<span style="color:red;">' + cA + "</span>" + cy + "</span>" + co + "</li>"
						} else {
							cr += '<li style="width: 140px;" traincode=' + cq + ' name="yxtrainli"><span style="font-size:15px;">' + cs + '<span style="color:red;">' + cA + "</span>" + cy + "</span>" + co + "</li>"
						}
					}
				}
			}
			$("#yxtrain_code").html(cr)
		} else {
			return false
		}
		if (cz.length > 0) {
			E(cm, cz.length)
		}
		$('li[name="yxtrainli"]').click(function() {
			if ($(this).attr("class") == "cur") {
				var cE = $('span[name="prior_train-span"]');
				for (var cC = 0; cC < cE.length; cC++) {
					var cD = $(cE[cC]).html();
					if (cD.indexOf($(this).attr("traincode")) > -1) {
						$(cE[cC]).children().click()
					}
				}
				$(this).removeClass()
			} else {
				$("#inp-train").val($(this).attr("traincode"));
				var cF = $('#prior_train span[name="prior_train-span"]').length;
				$("#add-train").click();
				if (cF < 6) {
					$(this).attr("class", "cur");
					$.chooseAutoSubmit()
				}
			}
		});
		return true
	}

	function E(cm, cn) {
		var co = Math.ceil(cn / yxTrainPageSize);
		$("#yxTrain_page").html(aE(cm, co)).show()
	}

	function aE(cu, cp) {
		var cq = "";
		cq += (cu == 0) ? "" : '<a href="javascript:void(0);" onclick="$.click_YX_page(' + (cu - 1) + ')" class="prev">上一页</a>';
		var cv = cu + 1;
		var cr = cp;
		var cs = 2;
		var ct = 5;
		var cm = (cv - cs) > 0 ? (cv + cs > cr ? cr - ct + 1 : cv - cs) : 1;
		var cn = cm + ct > cr ? cr + 1 : cm + ct;
		if (cr < ct) {
			for (var co = 1; co < cr + 1; co++) {
				if (cv == co) {
					cq += '<a href="javascript:void(0);" onclick="$.click_YX_page(' + (co - 1) + ')" class="on">' + (co) + "</a>"
				} else {
					cq += '<a href="javascript:void(0);" onclick="$.click_YX_page(' + (co - 1) + ')">' + (co) + "</a>"
				}
			}
		} else {
			for (var co = cm; co < cn; co++) {
				if (cv == co) {
					cq += '<a href="javascript:void(0);" onclick="$.click_YX_page(' + (co - 1) + ')" class="on">' + (co) + "</a>"
				} else {
					cq += '<a href="javascript:void(0);" onclick="$.click_YX_page(' + (co - 1) + ')">' + (co) + "</a>"
				}
			}
		}
		cq += (cu == cp - 1) ? "" : '<a href="javascript:void(0);" onclick="$.click_YX_page(' + (cu + 1) + ')" class="next">下一页</a>';
		return cq
	}

	function a5(cu, cp) {
		if (cp == 0) {
			return ""
		}
		var cq = "";
		cq += (cu == 0) ? "" : '<a href="javascript:void(0);" onclick="$.click_passenger_page(' + (cu - 1) + ')" class="prev">上一页</a>';
		var cv = cu + 1;
		var cr = cp;
		var cs = 2;
		var ct = 5;
		var cm = (cv - cs) > 0 ? (cv + cs > cr ? cr - ct + 1 : cv - cs) : 1;
		var cn = cm + ct > cr ? cr + 1 : cm + ct;
		if (cr < ct) {
			for (var co = 1; co < cr + 1; co++) {
				if (cv == co) {
					cq += '<a href="javascript:void(0);" onclick="$.click_passenger_page(' + (co - 1) + ')" class="on">' + (co) + "</a>"
				} else {
					cq += '<a href="javascript:void(0);" onclick="$.click_passenger_page(' + (co - 1) + ')">' + (co) + "</a>"
				}
			}
		} else {
			for (var co = cm; co < cn; co++) {
				if (cv == co) {
					cq += '<a href="javascript:void(0);" onclick="$.click_passenger_page(' + (co - 1) + ')" class="on">' + (co) + "</a>"
				} else {
					cq += '<a href="javascript:void(0);" onclick="$.click_passenger_page(' + (co - 1) + ')">' + (co) + "</a>"
				}
			}
		}
		cq += (cu == cp - 1) ? "" : '<a href="javascript:void(0);" onclick="$.click_passenger_page(' + (cu + 1) + ')" class="next">下一页</a>';
		return cq
	}

	function ch() {
		if ($("#sf2").is(":checked")) {
			return "0X00"
		} else {
			return "ADULT"
		}
	}
	jQuery.extend({
		chooseAutoSubmit: function() {
			if (!$("#autoSubmit").is(":disabled")) {
				if (!$("#autoSubmit").is(":checked")) {
					$("#autoSubmit").click()
				}
			}
		},
		init_ul4li: function() {
			var cm = [];
			var co = 0;
			cm[co++] = '<li><input name="cc_type" value="G" type="checkbox" class="check" /><label for="">GC-高铁/城际</label></li>';
			cm[co++] = '<li><input name="cc_type" value="D" type="checkbox" class="check" /><label for="">D-动车</label></li>';
			cm[co++] = '<li><input name="cc_type" value="Z" type="checkbox" class="check" /><label for="">Z-直达</label></li>';
			cm[co++] = '<li><input name="cc_type" value="T" type="checkbox" class="check" /><label for="">T-特快</label></li>';
			cm[co++] = '<li><input name="cc_type" value="K" type="checkbox" class="check" /><label for="">K-快速</label></li>';
			cm[co++] = '<li><input name="cc_type" value="QT" type="checkbox" class="check" /><label for="">其他</label></li>';
			$("#_ul_station_train_code").html(cm.join(""));
			if (train_tour_flag == "gc" && "Y" == isDwTicketResign) {
				var cq = $("#_ul_station_train_code li");
				for (var cn = 2, cp = cq.length; cn < cp; cn++) {
					cq.eq(cn).find("input").attr("disabled", "disabled");
					cq.eq(cn).find("label").attr("for", "").attr("style", "color: rgb(153, 153, 153)")
				}
			}
			$("#startendtime").html('<span class="b1" id="s_time">出发时间</span><br /><span class="b2" id="r_time">到达时间</span>');
			$("#floatstartendtime").html('<span class="b1" id="other_span_starttime">出发时间</span><br /><span class="b2" id="other_span_endtime">到达时间</span>')
		},
		parseDateFormat: function(cq) {
			var cm = "";
			var cn = cq.getFullYear();
			var cp = cq.getMonth() + 1;
			var co = cq.getDate();
			if (cp < 10) {
				cp = "0" + cp
			}
			if (co < 10) {
				co = "0" + co
			}
			cm = cn + "-" + cp + "-" + co;
			return cm
		},
		renderPassenger: function(cE) {
			if (!cE) {
				cE = 0
			}
			if (passengerAll) {
				var cq = $("#searchPassenger").val();
				var cm = [];
				if (cq != "" && cq != "输入乘客姓名") {
					var cC = passengerAll.length;
					for (var cz = 0; cz < cC; cz++) {
						var cy = passengerAll[cz];
						if (cy.passenger_name.indexOf(cq) > -1 || (cy.first_letter && cy.first_letter.toUpperCase().indexOf(cq.toUpperCase()) > -1)) {
							cm.push(cy)
						}
					}
				} else {
					cm = passengerAll.slice(passengerPageSize * (cE), Math.min(passengerPageSize * (cE + 1), passengerAll.length))
				}
				var cx = cm.length;
				var cv = [];
				var cr = 0;
				for (var cz = 0; cz < cx; cz++) {
					var cy = cm[cz];
					var cD = cy.passenger_type_name;
					if (!cD) {
						cD = ""
					}
					var cp = "";
					var cn = "";
					if ($("#sf2").is(":checked")) {
						if (cy.passenger_type != "3") {
							cp = " disabled='true' ";
							cn = " class='color999' "
						}
					}
					var cu = cy.total_times;
					if (cy.passenger_id_type_code == "2") {
						cp = " disabled='true' ";
						cn = " class='color999' title='请修改身份信息' "
					} else {
						if (cy.passenger_id_type_code == "1") {
							if (!isCanGP("1", cu)) {
								cp = " disabled='true' ";
								cn = " class='color999' title='请修改身份信息' "
							}
						} else {
							if (!isCanGP("B", cu)) {
								cp = " disabled='true' ";
								cn = " class='color999' title='请修改身份信息' "
							}
							if (!isCanGP("H", cu)) {
								cp = " disabled='true' ";
								cn = " class='color999' title='请修改身份信息' "
							}
						}
					}
					var cw = cD == "成人" ? cy.passenger_name : cy.passenger_name + "(" + cD + ")";
					cw = cw.substring(0, 9);
					if (cq != "" && cq != "输入乘客姓名") {
						if (cy.passenger_name.indexOf(cq) > -1 || (cy.first_letter && cy.first_letter.toUpperCase().indexOf(cq.toUpperCase()) > -1)) {
							cr++;
							if ($.pHasInSelected(cy)) {
								if (cn) {
									var ct = cn.indexOf("'");
									cn = cn.substring(0, ct + 1) + "cur " + cn.substring(ct + 1)
								} else {
									cn = "class='cur'"
								}
							}
							cv[cz] = "<li style='width:110px' " + cn + " p_value='" + cy.passenger_name + "(" + cD + ")(" + cy.passenger_id_no + ")' name='" + cy.passenger_type + "' codeType='" + cy.passenger_id_type_code + "' flag='" + cy.total_times + "'>" + cw + "</li>"
						}
					} else {
						cr++;
						if ($.pHasInSelected(cy)) {
							if (cn) {
								var ct = cn.indexOf("'");
								cn = cn.substring(0, ct) + "cur " + cn.substring(ct)
							} else {
								cn = "class='cur'"
							}
						}
						cv[cz] = "<li style='width:110px' " + cn + " p_value='" + cy.passenger_name + "(" + cD + ")(" + cy.passenger_id_no + ")'  name='" + cy.passenger_type + "' codeType='" + cy.passenger_id_type_code + "' flag='" + cy.total_times + "'>" + cw + "</li>"
					}
				}
				var cA = 100;
				var cB = 0;
				if (cr / 3 > 11) {
					cA = 310;
					cB = 258
				} else {
					cA = 100 + parseInt((cr / 3) * 25);
					cB = cA - 48
				}
				$("#sel-buyer").css("height", cA);
				$("#pContent").css("height", cB);
				$("#buyer-list").html(cv.join(""));
				var co = 0;
				if (cq != "" && cq != "输入乘客姓名") {
					co = cm.length
				} else {
					co = passengerAll.length
				}
				var cs = Math.ceil(co / passengerPageSize);
				$("#passenger_page").html(a5(cE, cs)).show()
			}
			$("#buyer-list li").click(function() {
				if ($(this).hasClass("color999")) {
					return
				}
				var cH = $("#setion_postion span").length;
				var cJ = $(this).attr("p_value");
				if (!$(this).hasClass("cur")) {
					if (cH < 6) {
						var cF = "";
						var cG = true;
						if (cJ.indexOf("成人") > -1 || cJ.indexOf("残疾军人、伤残人民警察") > -1) {
							cF = "<span name='" + cJ + "' class='sel-box w80'><a href='javascript:' onclick='$.addChildPassenger(\"" + cJ + "\");' style='position:static;background:none;width:auto;' title='您可点击此乘车人添加儿童票。'>" + cJ + "</a><a class='close' href='javascript:' onclick='$.removeSel(this,\"" + cJ + "\",1)'></a></span>";
							$("#setion_postion").append(cF);
							$.checkedPasseanger(cJ)
						} else {
							if (cJ.indexOf("学生") > -1) {
								var cI = $(this);
								if ($.checkSeatTypes()) {
									cF = "<span name='" + cJ + "' class='sel-box w80'>" + cJ + "<a class='close' href='javascript:' onclick='$.removeSel(this,\"" + cJ + "\",1)'></a></span>";
									$("#setion_postion").append(cF);
									$.checkedPasseanger(cJ)
								} else {
									$("#conifrmdialog_student_to_adult_context").html("当前选择的优先席别有不支持学生票的，是否选择购买成人票？");
									dhtmlx.createWin({
										winId: "confirmChangeStudentToAdult",
										closeWinId: ["close_conifrmdialog_student_to_adult", "cancel_dialog_student_to_adult"],
										callback: function() {
											$(cI).prop("checked", false)
										},
										okId: "goto_student_to_adult",
										okCallBack: function() {
											var cK = cJ.replace(/学生/, "成人");
											cF = "<span name='" + cJ + "' class='sel-box w80'>" + cK + "<a class='close' href='javascript:' onclick='$.removeSel(this,\"" + cJ + "\",1)'></a></span>";
											$("#setion_postion").append(cF);
											$.checkedPasseanger(cK)
										}
									})
								}
							} else {
								if (cJ.indexOf("儿童") > -1) {
									cF = "<span name='" + cJ + "' class='sel-box w80' title='如需修改旅客类型，请修改相应常用联系人信息。'>" + cJ + "<a class='close' href='javascript:' onclick='$.removeSel(this,\"" + cJ + "\",1)'></a></span>";
									$("#setion_postion").append(cF);
									$.checkedPasseanger(cJ)
								} else {
									cF = "<span name='" + cJ + "' class='sel-box w80'>" + cJ + "<a class='close' href='javascript:' onclick='$.removeSel(this,\"" + cJ + "\",1)'></a></span>";
									$("#setion_postion").append(cF);
									$.checkedPasseanger(cJ)
								}
							}
						}
						$(this).addClass("cur");
						$.chooseAutoSubmit()
					} else {
						dhtmlx.alert({
							title: "添加常用联系人",
							ok: "确定",
							text: "最多添加5位联系人",
							type: "alert-error"
						});
						$(this).removeClass("cur")
					}
				} else {
					$.each($("#setion_postion span"), function(cK, cL) {
						if (cJ == $(cL).attr("name")) {
							$(cL).remove();
							$.removePasseanger(cJ);
							return
						}
					});
					$(this).removeClass("cur")
				}
			})
		},
		reloadPassenger: function() {
			var cm = dhtmlx.modalbox({
				targSrc: '<div><img src="' + ctx + 'resources/images/loading.gif"></img></div>',
				callback: function() {}
			});
			$.ajax({
				type: "post",
				isTakeParam: false,
				cache: false,
				async: false,
				url: ctx + "confirmPassenger/getPassengerDTOs",
				timeout: 10000,
				error: function(cn, cp, co) {
					dhtmlx.modalbox.hide(cm)
				},
				success: function(cn) {
					dhtmlx.modalbox.hide(cm);
					if (cn.status) {
						if (cn.data.noLogin == "true") {
							bv();
							$("#floatTable").hide();
							a = $(window).scrollTop();
							Z()
						} else {
							if (cn.data.exMsg != "" && cn.data.exMsg != null && cn.data.exMsg != "null") {
								b(cn.data.exMsg);
								return
							}
							$("#sel-buyer").show();
							$("#sel-seat").hide();
							$("#sel-date").hide();
							$("#sel-buyer").css("left", $("#sear-sel").position().left + 80);
							$("#sel-buyer").css("left", $("#sear-sel").position().left + 80);
							$("#sel-buyer").css("top", $("#sear-sel").position().top + 4 * 28 + 16);
							passengerAll = cn.data.normal_passengers;
							if (!(passengerAll && passengerAll.length > 0)) {
								passengerAll = []
							}
							var cq = cn.data.dj_passengers;
							if (cq && cq.length > 0) {
								var cp = cq.length;
								for (var co = 0; co < cp; co++) {
									if (!$.checkIsHas(passengerAll, cq[co])) {
										passengerAll.push(cq[co])
									}
								}
							}
							two_isOpenClick = cn.data.two_isOpenClick;
							other_isOpenClick = cn.data.other_isOpenClick;
							$.renderPassenger()
						}
					}
				}
			})
		},
		checkIsHas: function(co, cp) {
			var cn = co.length;
			for (var cm = 0; cm < cn; cm++) {
				if (co[cm].passenger_name == cp.passenger_name && co[cm].passenger_id_type_code == cp.passenger_id_type_code && cp.passenger_id_no == co[cm].passenger_id_no) {
					return true
				}
			}
			return false
		},
		pHasInSelected: function(cp) {
			var cn = passengerChecked.length;
			if (cn > 0) {
				for (var cm = 0; cm < cn; cm++) {
					var co = passengerChecked[cm];
					if (co.passenger_name == cp.passenger_name && co.passenger_id_type_code == cp.passenger_id_type_code && co.passenger_id_no == cp.passenger_id_no) {
						return true
					}
				}
			}
			return false
		},
		showSelectBuyer: function() {
			$("#sel-seat").hide();
			$("#yxtraindiv").hide();
			$("#sel-date").hide();
			if (!passengerAll) {
				$.reloadPassenger()
			} else {
				var cm = $("#buyer-list li");
				for (var cn = 0; cn < cm.length; cn++) {
					var cp = $(cm[cn]).attr("name");
					var co = $(cm[cn]).attr("codeType");
					var cq = $(cm[cn]).attr("flag");
					if ($("#sf2").is(":checked")) {
						if (cp != "3") {
							$(cm[cn]).addClass("color999")
						} else {
							$(cm[cn]).removeClass("color999")
						}
					} else {
						$(cm[cn]).removeClass("color999")
					}
					if (co == "2") {
						$(cm[cn]).addClass("color999")
					} else {
						if (co == "1") {
							if (!isCanGP("1", cq)) {
								$(cm[cn]).addClass("color999")
							}
						} else {
							if (!isCanGP("B", cq)) {
								$(cm[cn]).addClass("color999")
							}
							if (!isCanGP("H", cq)) {
								$(cm[cn]).addClass("color999")
							}
						}
					}
				}
				$("#sel-buyer").show();
				$("#sel-buyer").css("left", $("#sear-sel").position().left + 80);
				$("#sel-buyer").css("top", $("#sear-sel").position().top + 4 * 28 + 16)
			}
		},
		click_YX_page: function(cn) {
			var co = $("#yxtraininput").val().toUpperCase();
			var cm = $("#yxtrain_code").height();
			if (u(co, cn)) {
				cl(1)
			} else {
				cl(3)
			}
			$("#yxtrain_code").css("height", cm)
		},
		click_passenger_page: function(cm) {
			$.renderPassenger(cm)
		},
		showYxTrain: function() {
			$("#yxtrain_code").css("height", "auto");
			$("#yxtrain_code li").removeClass();
			$("#yxtraininput").val("");
			$("#yxtraindiv").css("top", $("#showYxTrainSpan").offset().top + $("#showYxTrainSpan").outerHeight()).css("left", $("#showYxTrainSpan").offset().left).show();
			cl(2);
			var co = $("#fromStationText").val() + $("#toStationText").val() + $("#train_date").val();
			if (trainListForIE.length == 0 || yxTrainChange != co) {
				x = ch();
				var cq = x == "0X00" ? true : false;
				var cn = train_tour_flag == "fc" ? $.trim($("#back_train_date").val()) : $.trim($("#train_date").val());
				var cm = bI(cn, cq);
				if (!cm) {
					$("#yxtraindiv").hide();
					return
				}
				var cp = {
					"leftTicketDTO.train_date": cn,
					"leftTicketDTO.from_station": $("#fromStation").val(),
					"leftTicketDTO.to_station": $("#toStation").val(),
					purpose_codes: x
				};
				aT();
				$.ajax({
					type: "get",
					isTakeParam: false,
					beforeSend: function(cr) {
						cr.setRequestHeader("If-Modified-Since", "0");
						cr.setRequestHeader("Cache-Control", "no-cache")
					},
					url: ctx + CLeftTicketUrl,
					data: cp,
					timeout: 10000,
					success: function(ct) {
						if (ct.status) {
							if (ct.data == null || ct.data.length == 0) {
								cl(3);
								trainListForIE = [];
								return
							}
							if (ct.data.flag == 1) {
								ct.data = b2(ct.data.result, ct.data.map)
							}
							trainListForIE = [];
							for (var cu = 0; cu < ct.data.length; cu++) {
								trainListForIE.push(ct.data[cu].queryLeftNewDTO.station_train_code + "(" + ct.data[cu].queryLeftNewDTO.start_time + "--" + ct.data[cu].queryLeftNewDTO.arrive_time + ")")
							}
							if (train_tour_flag == "gc" && "Y" == isDwTicketResign) {
								var cA = [];
								for (var cu = 0, cB = ct.data.length; cu < cB; cu++) {
									var cs = ct.data[cu].queryLeftNewDTO;
									var cx = cs.station_train_code;
									cx = cx.substring(0, 1);
									if ("G" == cx || "D" == cx) {
										cA.push(ct.data[cu])
									}
								}
								ct.data = cA
							}
							if ($("#DW_SHOW_STR")[0]) {
								$("#DW_SHOW_STR").remove()
							}
							if ($("#hainan_limit_msg")[0]) {
								$("#hainan_limit_msg").remove()
							}
							$("#sear-sel").show();
							$("#sear-result").show();
							$("#t-list").show();
							$("#no_filter_ticket_2").hide();
							$("#no_filter_ticket").hide();
							var cr = "";
							var cw = "";
							if (train_tour_flag != null && train_tour_flag == "fc") {
								var cz = "<strong>".concat($("#fromStationText").val()).concat(" --> ").concat($("#toStationText").val()).concat("（").concat(aD($("#back_train_date").val())).concat('）</strong>共计<strong id="trainum">').concat(ct.data.length).concat("</strong>个车次");
								if (bV(ct.data)) {
									cr = "<p class='ad-gt' id='DW_SHOW_STR' data='1'>高铁动卧 夕发朝至 风雨无阻 省时省钱</p>"
								} else {
									if (hainan_limit_msg && ae(cp, ct.data)) {
										cw = "<p class='ad-gt' id='hainan_limit_msg'  style='font-size:13px;background:#fff6f6 left center no-repeat;font-weight:bold'>" + hainan_limit_msg + "</p>"
									}
								}
								if ($("#auto_query").is(":checked")) {
									var cy = "";
									for (var cv = 0; cv < 25; cv++) {
										cy = cy + "&nbsp;"
									}
									cz = cz.concat(cy + "<input type='checkbox' class='check' id='filterTic' /><div id='filterTicDiv' style='display:inline'><strong><label for='filterTic' style='cursor: pointer;'>仅查看刷到车次</label></strong></div>")
								}
								$("#sear-result>p").html(cz);
								if ($("#auto_query").is(":checked")) {
									$("#filterTic").bind("click", bf)
								}
							} else {
								var cz = "<strong>".concat($("#fromStationText").val()).concat(" --> ").concat($("#toStationText").val()).concat("（").concat(aD($("#train_date").val())).concat('）</strong>共计<strong id="trainum">').concat(ct.data.length).concat("</strong>个车次");
								if (bV(ct.data)) {
									cr = "<p class='ad-gt' id='DW_SHOW_STR' data='1'>高铁动卧 夕发朝至 风雨无阻 省时省钱</p>"
								} else {
									if (hainan_limit_msg && ae(cp, ct.data)) {
										cw = "<p class='ad-gt' id='hainan_limit_msg'  style='font-size:13px;background:#fff6f6 left center no-repeat;font-weight:bold'>" + hainan_limit_msg + "</p>"
									}
								}
								if ($("#auto_query").is(":checked")) {
									var cy = "";
									for (var cv = 0; cv < 25; cv++) {
										cy = cy + "&nbsp;"
									}
									cz = cz.concat(cy + "<input type='checkbox' class='check' id='filterTic' /><div id='filterTicDiv' style='display:inline'><strong><label for='filterTic' style='cursor: pointer;'>仅查看刷到车次</label></strong></div>")
								}
								$("#sear-result>p").html(cz);
								if ($("#auto_query").is(":checked")) {
									$("#filterTic").bind("click", bf)
								}
							}
							if (!$("#DW_SHOW_STR")[0]) {
								$("#sear-result>p").after(cr)
							}
							if (cw) {
								$("#sear-result>p").after(cw)
							}
							if (dwTranTimeStr) {
								clearInterval(dwTranTimeStr)
							}
							if ($("#DW_SHOW_STR")[0]) {
								dwTranTimeStr = window.setInterval(function() {
									if ($("#DW_SHOW_STR").attr("data") == "1") {
										$("#DW_SHOW_STR").attr("data", "2").html("夜行两千公里 最低不足千元")
									} else {
										$("#DW_SHOW_STR").attr("data", "1").html("高铁动卧 夕发朝至 风雨无阻 省时省钱")
									}
								}, 1300)
							}
							if ($("#hainan_limit_msg")[0]) {
								hainan_tip = null;
								hainan_tip = new Marquee({
									ID: "hainan_limit_msg",
									Direction: "left",
									Step: 1,
									Width: 0,
									Height: 0,
									Timer: 30,
									DelayTime: 0,
									WaitTime: 0,
									ScrollStep: 0
								})
							}
							a8 = ct.data;
							ah();
							bl(a8);
							n();
							bE(a8);
							bM();
							$("#queryLeftTable").html("");
							$("#trainum").html("");
							aK();
							if (bY.length < 0) {
								aO = true;
								$("#no_filter_ticket").show();
								$("#no_filter_ticket_msg_1").show();
								$("#no_filter_ticket_msg_2").hide();
								$("#trainum").html("0");
								return
							} else {
								aO = true;
								$("#trainum").html(bY.length);
								aA(bY);
								$.showYxTrainData()
							}
							yxTrainChange = $("#fromStationText").val() + $("#toStationText").val() + $("#train_date").val()
						} else {
							if (ct && ct.c_url) {
								CLeftTicketUrl = ct.c_url;
								aj(cp)
							}
						}
					}
				});
				yxTrainChange = co
			} else {
				$.showYxTrainData()
			}
			$("#sel-buyer").hide();
			$("#sel-seat").hide();
			$("#sel-date").hide()
		},
		showYxTrainData: function() {
			if (u($("#yxtraininput").val(), 0)) {
				$("#yxtraindiv").css("top", $("#showYxTrainSpan").offset().top + $("#showYxTrainSpan").outerHeight()).css("left", $("#showYxTrainSpan").offset().left).show();
				cl(1);
				$("#yxtraininput").focus()
			} else {
				cl(3)
			}
		},
		getMindateForCal: function() {
			if ($("#sf2").is(":checked")) {
				g = studentMindate
			} else {
				g = otherMindate
			}
			return g
		},
		getMaxdateForCal: function() {
			if ($("#sf2").is(":checked")) {
				D = studentMaxdate
			} else {
				D = otherMaxdate
			}
			return D
		}
	});

	function F() {
		$("#show_all_query_result").click(function() {
			bA = new Array();
			bo = new Array();
			N = new Array();
			$("#train_type_btn_all").removeClass().addClass("btn-all");
			$("#start_time_btn_all").removeClass().addClass("btn-all");
			$("#arrive_time_btn_all").removeClass().addClass("btn-all");
			$("#seat_type_btn_all").removeClass().addClass("btn-all");
			$("#from_station_name_all").removeClass().addClass("btn-all");
			$("#to_station_name_all").removeClass().addClass("btn-all");
			$("#sear-sel-bd input").each(function() {
				if (this.checked) {
					this.checked = false
				}
			});
			if (ax) {
				ax.setComboText("")
			}
			$("#avail_ticket").attr("checked", false);
			aH()
		})
	}

	function at() {
		var cm = $("#queryPriceTemplate").html().replace("<!--", "").replace("-->", "");
		$.templates({
			priceTableTemplate: cm
		});
		var cm = $("#fromStationNameTemplate").html().replace("<!--", "").replace("-->", "");
		$.templates({
			stationNameTableTemplate: cm
		});
		var cm = $("#toStationNameTemplate").html().replace("<!--", "").replace("-->", "");
		$.templates({
			toStationNameTableTemplate: cm
		});
		var cm = $("#seatTypeTemplate").html().replace("<!--", "").replace("-->", "");
		$.templates({
			seatTypeTemplate: cm
		});
		var cm = $("#stationinfoTemplate").html().replace("<!--", "").replace("-->", "");
		$.templates({
			stationinfoTemplate: cm
		})
	}

	function bE(cn) {
		dhtmlXCombo_defaultOption.prototype._DrawHeaderButton = function() {};
		$("#train_combo_box").hide();
		var cm = [];
		if (!ax) {
			ax = new dhtmlXCombo("train_combo_box_div", "cc", 90)
		} else {
			ax.setComboText("")
		}
		ax.clearAll();
		$(cn).each(function() {
			cm.push([this.queryLeftNewDTO.station_train_code, this.queryLeftNewDTO.station_train_code])
		});
		ax.addOption(cm);
		ax.enableFilteringMode(true);
		ax.attachEvent("onChange", function() {
			if (ax.getComboText() != "") {
				if ($("#iLcear").is(":hidden")) {
					$("#iLcear").show()
				}
			}
			aH()
		});
		if (!$("#iLcear")[0]) {
			$(".dhx_combo_box ").append($('<span style="display: none;" class="i-clear dhx_combo_img_iClear" id="iLcear"></span>'));
			$("#iLcear").on("click", function() {
				if (ax) {
					ax.setComboText("");
					$(this).hide()
				}
			})
		}
		$(".dhx_combo_input").on("keyup", function() {
			if ($(this).val() == "") {
				$("#iLcear").hide()
			} else {
				if ($("#iLcear").is(":hidden")) {
					$("#iLcear").show()
				}
			}
		})
	}

	function aq() {
		if (!b9) {
			b9 = new dhtmlXWindows();
			b9.enableAutoViewport(true);
			b9.setSkin("dhx_terrace");
			b9.attachViewportTo("winVP");
			b9.setImagePath(ctx + "resources/js/rich/windows/imgs/")
		}
		$("#username").keydown(function() {
			login_errorMsg_hide()
		});
		$("#password").keydown(function() {
			login_errorMsg_hide()
		})
	}

	function bt() {
		b9.window("login").hide();
		b9.window("login").setModal(false)
	}

	function bv() {
		if (b9.window("login")) {
			b9.window("login").setModal(false);
			b9.window("login").hide()
		}
		a0 = b9.createWindow("login", 0, 0, 400, 350);
		var cm, co;
		if (typeof(TouLocal) != "undefined" && TouLocal.checkZByTargeElement("")) {
			cm = $(window).width() / 2 - 208;
			co = ce() + ($(window).height() / 2 - 232)
		} else {
			cm = $(window).width() / 2 - 200;
			co = ce() + ($(window).height() / 2 - 205)
		}
		a0.attachObject("relogin");
		if (if_show_pass_code_login == "Y") {
			a0.setDimension($("#content").width(), $("#content").height() + 10)
		} else {
			a0.setDimension(530, 343);
			cm = $(window).width() / 2 - 250
		}
		$(".dhtmlx_window_active").height($("#content").height());
		$(".dhtmlx_window_active").css({
			left: cm,
			top: co
		});
		a0.bringToTop();
		b9.window("login").clearIcon();
		b9.window("login").denyResize();
		a0.button("park").hide();
		a0.button("minmax1").hide();
		a0.hideHeader();
		if (if_show_pass_code_login == "Y") {
			var cn = $(".login .touclick-image").attr("src");
			refreshImgUAM("login", "sjrand")
		}
		a0.setModal(true);
		$("#relogin_close").click(function() {
			bh();
			var cp = $(window).scrollTop();
			var cq = $("#float").position().top;
			if (cp > cq + 30) {
				$("#floatTable").show()
			}
			bt()
		});
		if (typeof(touclickHook_leftTicketLogin) === "function") {
			touclickHook_leftTicketLogin()
		}
	}

	function bh() {
		aP();
		$("#username").val("");
		$("#password").val("");
		$("#randCode").val("");
		b3()
	}

	function ce() {
		if ("pageYOffset" in window) {
			return window.pageYOffset
		} else {
			if (document.compatMode == "BackCompat") {
				return document.body.scrollTop
			} else {
				return document.documentElement.scrollTop
			}
		}
	}

	function aP() {
		$("#username").add($("#password")).add($("#randCode")).add($("#randCode2")).removeClass("error")
	}

	function B(cq) {
		var cn = /^(13[0-9])|(14[0-9])|(15[0-9])|(18[0-9])|(17[0-9])\d{8}$/;
		var cm = /^[A-Za-z]{1}([A-Za-z0-9]|[_]){0,29}$/;
		var cp = /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i;
		var co = true;
		aP();
		if ("" == cq || cq == null || cq == uninputmsg || cq == "admin") {
			$("#username").removeClass("inptxt w200").addClass("inptxt w200 error");
			co = login_messages.userNameEmpty
		} else {
			if (!cm.test(cq) && !cp.test(cq) && !cn.test(cq)) {
				$("#username").removeClass("inptxt w200").addClass("inptxt w200 error");
				co = login_messages.userNameFormat
			}
		}
		return co
	}

	function bx(cm) {
		var cn = true;
		aP();
		if ("" == cm || cm == null) {
			$("#password").removeClass("inptxt w200").addClass("inptxt w200 error");
			cn = login_messages.passwordEmpty
		} else {
			if (cm.length < 6) {
				$("#password").removeClass("inptxt w200").addClass("inptxt w200 error");
				cn = login_messages.passwordLength
			}
		}
		return cn
	}

	function aS() {
		var co = $.trim($("#username").val());
		var cm = $.trim($("#password").val());
		var cn = B(co);
		return typeof(cn) === "boolean" ? bx(cm) : cn
	}

	function A() {
		var cn = false;
		var cm = false;
		$("#username").on("keyup", function() {
			aB = true
		}).blur(function() {
			if (aB) {
				var co = $.trim($("#username").val());
				cn = B(co);
				if (if_show_pass_code_login == "Y") {
					if (typeof(cn) !== "boolean") {
						showError($("#randCode")[0], cn)
					} else {
						if (cn === true) {
							showError($("#randCode")[0]).hide()
						}
					}
				} else {
					if (typeof(cn) !== "boolean") {
						login_errorMsg(cn)
					} else {
						if (cn === true) {
							login_errorMsg_hide()
						}
					}
				}
			}
		});
		$("#password").blur(function() {
			if (aB) {
				var co = $.trim($("#password").val());
				if (if_show_pass_code_login == "Y") {
					if (cn === true && typeof(cm = bx(co)) !== "boolean") {
						showError($("#randCode")[0], cm)
					} else {
						if (cn === true && cm === true) {
							showError($("#randCode")[0]).hide()
						}
					}
				} else {
					if (cn === true && typeof(cm = bx(co)) !== "boolean") {
						login_errorMsg(cm)
					} else {
						if (cn === true && cm === true) {
							login_errorMsg_hide()
						}
					}
				}
			}
		})
	}

	function aa(cn, cm) {
		$("#loginSubAsyn").unbind("click");
		$("#loginSubAsyn").click(function() {
			var co = aS();
			if (if_show_pass_code_login == "Y" && !verifyRandCodeUAM($("#randCode")[0], co)) {
				return
			}
			if (if_show_pass_code_login == "N" && typeof(co) !== "boolean") {
				login_errorMsg(co);
				return
			}
			$.ajax({
				url: passport_login,
				data: {
					username: $("#username").val(),
					password: $("#password").val(),
					appid: passport_appId
				},
				dataType: "json",
				type: "POST",
				xhrFields: {
					withCredentials: true
				},
				success: function(cp) {
					if (cp.result_code == 0) {
						$.ajax({
							type: "POST",
							url: passport_authuam,
							async: false,
							data: {
								appid: passport_appId
							},
							dataType: "jsonp",
							jsonp: "callback",
							success: function(cq) {
								if (cq.result_code == 0) {
									var cr = cq.newapptk || cq.apptk;
									$.ajax({
										type: "POST",
										async: false,
										url: ctx + passport_authclient,
										data: {
											tk: cr
										},
										datatype: "json",
										success: function(cs) {
											if (cs.result_code == 0) {
												bt();
												loginAsyn(cs.username);
												S(cn, cm)
											}
										},
										error: function() {}
									})
								}
							},
							error: function() {}
						})
					} else {
						if (if_show_pass_code_login == "Y") {
							showSuc($("#randCode")[0]).hide()
						} else {
							login_errorMsg_hide()
						}
						if (if_show_pass_code_login == "Y") {
							refreshImgUAM("login", "sjrand")
						}
						$("#password").val("");
						$("#randCode").val("");
						if (cp.result_message != null) {
							if (cp.result_message == "登录名不存在!") {
								aB = false;
								aP();
								$("#username").removeClass("error").focus()
							} else {
								if (cp.result_message == "验证码不正确！" && cp.result_message != "登录名不存在!") {
									aP();
									$("#randCode").removeClass("inptxt w100").addClass("inptxt w200 error");
									$("#randCode").focus()
								} else {
									if (cp.result_message != "验证码不正确！" && cp.result_message != "登录名不存在!") {
										aP();
										$("#password").removeClass("inptxt w200").addClass("inptxt w200 error");
										$("#password").focus()
									}
								}
							}
							if (if_show_pass_code_login == "Y") {
								showError($("#randCode")[0], cp.result_message)
							} else {
								login_errorMsg(cp.result_message)
							}
						}
					}
				}
			})
		})
	}

	function Z() {
		var cm = false;
		$("#loginSubAsyn").unbind("click");
		$("#loginSubAsyn").click(function() {
			if (!cm) {
				var cn = aS();
				if (if_show_pass_code_login == "Y" && !verifyRandCodeUAM($("#randCode")[0], cn)) {
					cm = false;
					return
				}
				cm = true;
				$("#loginForm").ajaxSubmit({
					url: passport_login,
					data: {
						username: $("#username").val(),
						password: $("#password").val(),
						appid: passport_appId
					},
					dataType: "json",
					type: "POST",
					xhrFields: {
						withCredentials: true
					},
					success: function(co) {
						if (co.result_code == 0) {
							$.ajax({
								type: "POST",
								url: passport_authuam,
								async: false,
								data: {
									appid: passport_appId
								},
								dataType: "jsonp",
								jsonp: "callback",
								success: function(cp) {
									if (cp.result_code == 0) {
										var cq = cp.newapptk || cp.apptk;
										$.ajax({
											type: "POST",
											async: false,
											url: ctx + passport_authclient,
											data: {
												tk: cq
											},
											datatype: "json",
											success: function(cr) {
												if (cr.result_code == 0) {
													bt();
													loginAsyn(cr.username)
												}
											},
											error: function() {}
										})
									}
								},
								error: function() {}
							})
						} else {
							$("#i-ok").hide();
							if (if_show_pass_code_login == "Y") {
								refreshImgUAM("login", "sjrand")
							}
							$("#password").val("");
							$("#randCode").val("");
							if (co.result_message != null) {
								if (co.result_message == "登录名不存在!") {
									aB = false;
									aP();
									$("#username").removeClass("inptxt w200").addClass("inptxt w200 error");
									$("#username").focus()
								} else {
									if (co.result_message == "验证码不正确！" && co.result_message != "登录名不存在!") {
										aP();
										$("#randCode").removeClass("inptxt w100").addClass("inptxt w200 error");
										$("#randCode").focus()
									} else {
										if (co.result_message != "验证码不正确！" && co.result_message != "登录名不存在!") {
											aP();
											$("#password").removeClass("inptxt w200").addClass("inptxt w200 error");
											$("#password").focus()
										}
									}
								}
								if (if_show_pass_code_login == "Y") {
									showError($("#randCode")[0], co.result_message)
								} else {
									login_errorMsg(co.result_message)
								}
							}
						}
					},
					complete: function() {
						cm = false
					}
				})
			}
		})
	}

	function aV() {
		window.sucessCallback = function() {
			by = $("#randCode2").val();
			$("#back_edit").trigger("click");
			var cm = "99999GGGGG";
			var co = "##CCT##PPT##CPT##PXT##SBT##PBD##JOD##HPD##SHD##QTP##TSP##TJP##";
			var cn = "##CBP##DIP##JGK##ZEK##UUH##NKH##ESH##OHH##AOH##";
			if (isAsync == ticket_submit_order.request_flag.isAsync) {
				if (K.queryLeftNewDTO.train_no.indexOf(cm) > -1 && co.indexOf(K.queryLeftNewDTO.from_station_telecode) > -1 && cn.indexOf(K.queryLeftNewDTO.to_station_telecode) > -1) {
					dhtmlx.createWin({
						winId: "confirmG1234",
						closeWinId: ["close_conifrmdialog_G1234", "cancel_dialog_G1234"],
						okId: "goto_integration_G1234",
						okCallBack: function() {
							q()
						},
						callback: function() {
							return
						}
					})
				} else {
					q()
				}
			} else {
				if (K.queryLeftNewDTO.train_no.indexOf(cm) > -1 && co.indexOf(K.queryLeftNewDTO.from_station_telecode) > -1 && cn.indexOf(K.queryLeftNewDTO.to_station_telecode) > -1) {
					dhtmlx.createWin({
						winId: "confirmG1234",
						closeWinId: ["close_conifrmdialog_G1234", "cancel_dialog_G1234"],
						okId: "goto_integration_G1234",
						okCallBack: function() {
							ck()
						},
						callback: function() {
							return
						}
					})
				} else {
					ck()
				}
			}
			return
		}
	}

	function b3() {
		$("#username").css("color", "#333");
		$("#password").css("color", "#333");
		$("#randCode").css("color", "#333");
		if ($("#username").val() == "" || $("#username").val() == uninputmsg || $("#username").val() == null || $("#username").val() == "admin") {
			$("#username").css("color", "#999");
			$("#username").val(uninputmsg);
			$("#password").val("")
		}
		$("#username").focus(function() {
			var cm = $("#username").val();
			if (cm == uninputmsg) {
				$("#username").css("color", "#333");
				$("#username").val("");
				$("#password").val("")
			}
		}).blur(function() {
			var cm = $("#username").val();
			if (cm == "") {
				$("#username").css("color", "#999");
				$("#username").val(uninputmsg)
			}
		})
	}

	function ag() {
		$("#forget_my_password_id").on("click", function(cm) {
			otsRedirect("post", ctx + "forgetPassword/initforgetMyPassword")
		})
	}

	function aT() {
		var cm = 1;
		var cs;
		var cx;
		var co;
		var cr = true;
		var cq = true;
		var cv = true;
		var cz;
		var cn;
		var cw = false;
		var ct = false;
		var cy = false;
		co = dataNumber;
		var cu;
		if (train_tour_flag != null && train_tour_flag != "" && train_tour_flag == "fc") {
			cu = jQuery.inArray($("#back_train_date").val().substring(5, 10), change_dates_arr)
		} else {
			cu = jQuery.inArray($("#train_date").val().substring(5, 10), change_dates_arr)
		}
		if (cu != "-1") {
			cu = cu + 1;
			cz = firstShow;
			cn = endShow;
			if (parseInt(cu) >= parseInt(firstShow) && parseInt(cu) <= parseInt(endShow)) {
				if (isOther) {
					if (parseInt(endShow) > parseInt(other_control)) {
						endShow = other_control;
						ct = true;
						cw = true
					}
				} else {
					if (parseInt(endShow) > parseInt(stu_control)) {
						endShow = stu_control
					}
				}
				if (!ct) {
					cr = false;
					cq = false;
					cv = false;
					cx = endShow + 1
				}
			} else {
				cw = true;
				firstShow = cu;
				endShow = firstShow + 19;
				if (isOther) {
					if (parseInt(endShow) > parseInt(other_control)) {
						endShow = other_control;
						ct = true
					}
				} else {
					if (parseInt(endShow) > parseInt(stu_control)) {
						endShow = stu_control;
						ct = true
					}
				}
				if (!ct) {
					cs = firstShow - 1;
					cx = endShow + 1;
					if (cs < cm) {
						cr = false
					}
				}
			}
			if (isOther) {
				if (other_control < dataNumber) {
					cy = true
				}
			} else {
				if (stu_control < dataNumber) {
					cy = true
				}
			}
			if (ct) {
				cw = true;
				firstShow = endShow - 19;
				cs = firstShow - 1;
				if (cy) {
					cq = true;
					cx = endShow + 1;
					co = dataNumber
				} else {
					cq = false
				}
				if (train_tour_flag != null && train_tour_flag != "" && train_tour_flag == "fc") {
					$("#back_train_date").val(fullDateArr[cu - 1])
				} else {
					$("#train_date").val(fullDateArr[cu - 1])
				}
			}
			if (parseInt(firstShow) < 1) {
				firstShow = 1
			}
			if (cr) {
				for (var cp = cm; cp <= cs; cp++) {
					$("#date_range>ul>li:nth-child(" + cp + ")").hide()
				}
			}
			if (cq) {
				for (var cp = cx; cp <= co; cp++) {
					$("#date_range>ul>li:nth-child(" + cp + ")").hide()
				}
			}
			if (cv) {
				for (var cp = firstShow; cp <= endShow; cp++) {
					$("#date_range>ul>li:nth-child(" + cp + ")").show()
				}
			}
			$("#date_range>ul>li").removeClass("sel");
			if (cw) {
				$("#date_range>ul>li:nth-child(" + cz + ")").children("span:first").removeClass();
				$("#date_range>ul>li:nth-child(" + cz + ")").children("span:last").removeClass();
				$("#date_range>ul>li:nth-child(" + cn + ")").removeClass();
				$("#date_range>ul>li:nth-child(" + firstShow + ")").children("span:first").addClass("first");
				$("#date_range>ul>li:nth-child(" + firstShow + ")").children("span:last").addClass("first");
				$("#date_range>ul>li:nth-child(" + firstShow + ")").children().addClass("first");
				$("#date_range>ul>li:nth-child(" + endShow + ")").addClass("end")
			}
			$("#date_range>ul>li:nth-child(" + cu + ")").addClass("sel");
			$("#date_range>ul>li:nth-child(" + cu + ")").children("span:last-child").removeClass();
			$("#date_range>ul>li:nth-child(" + cu + ")").children("span:first-child").addClass("hide");
			bR = $("#date_range>ul>li:nth-child(" + cu + ")").children("span:first-child").text()
		}
	}

	function bN() {
		$("#query_ticket").unbind("click");
		$("#query_ticket_stu").unbind("click");
		$("#query_ticket").removeClass().addClass("btn92s btn-disabled");
		$("#query_ticket_stu").removeClass().addClass("btn92s btn-disabled");
		bj();
		setTimeout(function() {
			cj();
			bg();
			$("#query_ticket").removeClass().addClass("btn92s");
			$("#query_ticket_stu").removeClass().addClass("btn92s");
			if (train_tour_flag != "gc" && train_tour_flag != "fc") {
				if (ClickWho == "0X00") {
					$("#query_ticket").unbind();
					$("#query_ticket").removeClass().addClass("btn92s btn-disabled");
					$("#query_ticket_stu").removeClass().addClass("btn92s")
				}
				if (ClickWho == "00") {
					$("#query_ticket_stu").unbind();
					$("#query_ticket_stu").removeClass().addClass("btn92s btn-disabled");
					$("#query_ticket").removeClass().addClass("btn92s")
				}
			}
			if (isstudentDate) {
				$("#query_ticket_stu").unbind();
				$("#query_ticket_stu").removeClass().addClass("btn92s btn-disabled");
				$("#query_ticket").removeClass().addClass("btn92s")
			}
		}, 1000)
	}
	changeArriveDate = function(cn, cm) {
		cn = cn.replace(":", "");
		cm = cm.replace(":", "");
		hour_value = Number(cn.substring(0, 2)) + Number(cm.substring(0, 2));
		min_value = Number(cn.substring(2, 4)) + Number(cm.substring(2, 4));
		if (min_value >= 60) {
			hour_value = hour_value + 1
		}
		if (hour_value >= 24 && hour_value < 48) {
			return "次日"
		} else {
			if (hour_value >= 48 && hour_value < 72) {
				return "两日"
			} else {
				if (hour_value >= 72) {
					return "三日"
				} else {
					return "当日"
				}
			}
		}
	};
	changeLiShi = function(cm) {
		if (cm.substring(0, 1) == "0") {
			if (cm.substring(1, 2) == "0") {
				if (cm.substring(3, 4) == "0") {
					cm = cm.substring(4, 5) + "分"
				} else {
					cm = cm.substring(3, 5) + "分"
				}
			} else {
				cm = cm.substring(1, 2) + "小时" + cm.substring(3, 5) + "分"
			}
		} else {
			if (cm.substring(3, 5) == "00") {
				cm = cm.substring(0, 2) + "小时"
			} else {
				cm = cm.substring(0, 2) + "小时" + cm.substring(3, 5) + "分"
			}
		}
		return cm
	};
	isNum = function(cm) {
		return parseInt(cm)
	};
	buttonText = function() {
		return "预订"
	};

	function ao() {
		if ($("#sf2").is(":checked")) {
			if (C($("#train_date").val()) > C(init_maxPeriod) - 24 * 60 * 60 * 1000) {
				bj()
			} else {
				bg()
			}
		}
	}

	function ap() {
		if (train_tour_flag == "fc") {
			var cm = $("#back_train_date").val();
			z("back_train_date")
		} else {
			var cm = $("#train_date").val();
			z("train_date")
		}
		if (rqChecked.length == 0) {
			rqChecked.push(cm)
		}
		var cn = false;
		if (cm != rqChecked[0]) {
			for (var co = 0; co < rqChecked.length; co++) {
				if (cm == rqChecked[co]) {
					cn = true;
					rqChecked.splice(co, 1);
					$("#date-list input[scode=" + rqChecked[0] + "]").prop("checked", false);
					rqChecked.splice(0, 1, cm);
					$("#prior_date span[name=" + cm + "]").remove();
					break
				}
			}
			if (!cn) {
				$("#date-list input[scode=" + rqChecked[0] + "]").prop("checked", false);
				rqChecked.splice(0, 1, cm);
				$("#date-list input[scode=" + rqChecked[0] + "]").prop("checked", true)
			}
		}
	}
	$("#train_date").focus(function() {
		$("#train_date").jcalendar({
			isSingle: false,
			startDate: $.getMindateForCal(),
			endDate: $.getMaxdateForCal(),
			onpicked: function() {
				ap();
				$("#train_date").blur();
				var cm = $("#train_date").val();
				var cn = $("#back_train_date").val();
				if ($("#wf").is(":checked")) {
					if (!cn | C(cm) > C(cn)) {
						$("#back_train_date").val(cm)
					}
				}
				aT()
			}
		})
	});
	$("#date_icon_1").click(function() {
		$("#train_date").focus()
	});
	$("#back_train_date").focus(function() {
		$("#back_train_date").jcalendar({
			isSingle: false,
			startDate: $("#train_date").val(),
			endDate: $.getMaxdateForCal(),
			onpicked: function() {
				ap();
				$("#back_train_date").blur();
				aT()
			}
		})
	});
	$("#date_icon_2").click(function() {
		$("#back_train_date").focus()
	});
	String.prototype.toDate = function() {
		style = "yyyy-MM-dd hh:mm";
		var cp = {
			"y+": "y",
			"M+": "M",
			"d+": "d",
			"h+": "h",
			"m+": "m"
		};
		var cm = {
			y: "",
			M: "",
			d: "",
			h: "00",
			m: "00"
		};
		var co = style;
		for (var cn in cp) {
			if (new RegExp("(" + cn + ")").test(style)) {
				cm[cp[cn]] = this.substring(co.indexOf(RegExp.$1), co.indexOf(RegExp.$1) + RegExp.$1.length)
			}
		}
		return new Date(cm.y, cm.M - 1, cm.d, cm.h, cm.m)
	};

	function z(cq) {
		if (cq == "back_train_date" && ClickWho != "0X00") {
			return
		}
		var cm = ($("#" + cq).val().split(" ")[0] + " 00:00:00").toDate().getTime();
		var cs = stu_start_train_date.split("&");
		var co = stu_end_tain_date.split("&");
		var cn = false;
		for (var cp = 0, cr = cs.length; cp < cr; cp++) {
			if (cm >= cs[cp].toDate().getTime() && cm <= co[cp].toDate().getTime()) {
				cn = true;
				break
			}
		}
		if (cn) {
			$("#sf2").attr("disabled", false);
			$("#sf2_label").removeClass("color999")
		} else {
			$("#sf2").attr("checked", false);
			$("#sf1")[0]["checked"] = "checked";
			$("#sf2").attr("disabled", true);
			$("#sf2_label").addClass("color999")
		}
	}

	function bX(cm) {
		if (isSaveQueryLog == "Y") {
			$.ajax({
				type: "get",
				isTakeParam: false,
				beforeSend: function(cn) {
					cn.setRequestHeader("If-Modified-Since", "0");
					cn.setRequestHeader("Cache-Control", "no-cache")
				},
				url: ctx + "leftTicket/log",
				data: cm,
				timeout: 15000,
				error: function(cn, cp, co) {},
				success: function(cn) {}
			})
		}
	}
	var aR = 0;
	var X = new Array();

	function U() {
		$("div#id-seat-sel div.sel-item a").on("click", function() {
			if ($(this).attr("class") == "cur") {
				$(this).removeClass("cur");
				aR--;
				var cn = $(this).attr("id");
				$.each(X, function(co, cq) {
					var cp = $(cq).attr("id");
					if (cn == cp) {
						X.splice(co, 1)
					}
				});
				$("#selectNo").html(aR + "/" + tickets_info.length)
			} else {
				X.push($(this));
				$(this).addClass("cur");
				if (aR == tickets_info.length) {
					var cm = X[aR - 1];
					$(cm).removeClass("cur");
					X.splice(aR - 1, 1);
					return
				}
				aR++;
				$("#selectNo").html(aR + "/" + tickets_info.length)
			}
		})
	}

	function T() {
		ak();
		if (tickets_info && tickets_info.length > 0) {
			var cp = "Y";
			var cm = tickets_info[0].seat_type;
			for (var co = 0; co < tickets_info.length; co++) {
				var cn = tickets_info[co];
				if (cn.seat_type != cm) {
					cp = "N";
					break
				}
			}
			if (canChooseSeats && "Y" == canChooseSeats && "Y" == cp) {
				if (choose_Seats) {
					if ("M" == cm && choose_Seats.indexOf("M") > -1) {
						$("#id-seat-sel").css("display", "block");
						$("#yideng1").css("display", "block");
						if (tickets_info.length > 1) {
							$("#yideng2").css("display", "block")
						}
						$("#notice_1_id").html("*选座后如果系统票额不足，系统将随机为您申请席位。")
					}
					if ("O" == cm && choose_Seats.indexOf("O") > -1) {
						$("#id-seat-sel").css("display", "block");
						$("#erdeng1").css("display", "block");
						if (tickets_info.length > 1) {
							$("#erdeng2").css("display", "block")
						}
						$("#notice_1_id").html("*选座后如果系统票额不足，系统将随机为您申请席位。")
					}
					if ("P" == cm && choose_Seats.indexOf("P") > -1) {
						$("#id-seat-sel").css("display", "block");
						$("#tedeng1").css("display", "block");
						if (tickets_info.length > 1) {
							$("#tedeng2").css("display", "block")
						}
						$("#notice_1_id").html("*选座后如果系统票额不足，系统将随机为您申请席位。")
					}
					if ("9" == cm && choose_Seats.indexOf("9") > -1) {
						$("#id-seat-sel").css("display", "block");
						$("#tedeng1").css("display", "block");
						if (tickets_info.length > 1) {
							$("#tedeng2").css("display", "block")
						}
						$("#notice_1_id").html("*选座后如果系统票额不足，系统将随机为您申请席位。")
					}
				}
			}
		}
	}

	function ak() {
		$("div#id-seat-sel div.sel-item a").removeClass("cur");
		aR = 0;
		X = new Array();
		$("#selectNo").html(aR + "/" + tickets_info.length);
		$("#id-seat-sel.sel-item").css("display", "none");
		$("#id-seat-sel").css("display", "none");
		$("#notice_1_id").html("");
		$("#yideng1").css("display", "none");
		$("#yideng2").css("display", "none");
		$("#erdeng1").css("display", "none");
		$("#erdeng2").css("display", "none");
		$("#tedeng1").css("display", "none");
		$("#tedeng2").css("display", "none")
	}

	function bD() {
		var cm = "";
		$.each($("div#id-seat-sel div.seat-sel-bd a"), function() {
			if ($(this).attr("class") == "cur") {
				var cn = $(this).attr("id");
				cm += cn
			}
		});
		return cm
	}

	function bk() {
		if (aR != 0 && aR != tickets_info.length) {
			$("#sy_ticket_num_id").html("<span style='color:red;'>请按照乘车人个数选座对应的席位。</span>");
			return false
		} else {
			return true
		}
	}

	function b6() {
		b0();
		if (tickets_info && tickets_info.length > 0) {
			if (canChooseBeds && "Y" == canChooseBeds) {
				$("#id-bed-sel").css("display", "block");
				$("#notice_1_id").html("*选铺后如果系统票额不足，系统将随机为您申请铺位。");
				if (isCanChooseMid && "Y" == isCanChooseMid) {
					$("#mid_bed").css("display", "block")
				} else {
					$("#mid_bed").css("display", "none")
				}
			} else {
				$("#id-bed-sel").css("display", "none")
			}
		}
	}
	numSet = function(cp, cm) {
		var cu = parseInt($("#x_no").text());
		var cq = parseInt($("#z_no").text());
		var co = parseInt($("#s_no").text());
		var cs = tickets_info.length;
		var cn = cu + cq + co;
		if ("add" == cp) {
			if (cn < cs) {
				var ct = document.getElementById(cm).innerText;
				var cr = parseInt(ct) + 1;
				document.getElementById(cm).innerText = cr;
				$("#selectBedNo").html(cn + 1 + "/" + cs)
			}
		} else {
			var ct = document.getElementById(cm).innerText;
			if (cn > 0 && parseInt(ct) > 0) {
				var cr = parseInt(ct) - 1;
				document.getElementById(cm).innerText = cr;
				$("#selectBedNo").html(cn - 1 + "/" + cs)
			}
		}
	};

	function b0() {
		$("#x_no").html("0");
		$("#z_no").html("0");
		$("#s_no").html("0");
		$("#selectBedNo").html(0 + "/" + tickets_info.length);
		$("#confirmDiv").css("padding", "20px 0");
		$("#checktrain").css("display", "none")
	}

	function aL() {
		var cm = $("#x_no").text();
		var cn = $("#z_no").text();
		var co = $("#s_no").text();
		return cm + cn + co
	}
})();

function checkG1234(g, f, c, h, b) {
	var a = "99999GGGGG";
	var e = "##CCT##PPT##CPT##PXT##SBT##PBD##JOD##HPD##SHD##QTP##TSP##TJP##";
	var d = "##CBP##DIP##JGK##ZEK##UUH##NKH##ESH##OHH##AOH##";
	if (c.indexOf(a) > -1 && e.indexOf(h) > -1 && d.indexOf(b) > -1) {
		dhtmlx.createWin({
			winId: "confirmG1234",
			closeWinId: ["close_conifrmdialog_G1234", "cancel_dialog_G1234"],
			okId: "goto_integration_G1234",
			okCallBack: function() {
				submitOrderRequest(g, f)
			},
			callback: function() {
				return
			}
		})
	} else {
		submitOrderRequest(g, f)
	}
}

function refreshImgUAM(c, e, d) {
	if ($(".login .touclick-image").attr("src").indexOf(passport_captcha) != -1) {
		TouClick.get("touclick-" + TouLocal.getRandCodeName(d)).reload();
		return
	}
	var h = "randCode";
	if (targetelement[0] !== "") {
		h += "_" + targetelement[0]
	}
	var b = $("#" + targetdiv[0]),
		g = b.data("code_type");
	var j = "sjrand";
	var f = "E";
	var a = passport_captcha + "?login_site=" + f + "&module=" + g + "&rand=" + j;
	TouClick.ready(function() {
		var k = TouClick.get("touclick-" + h).start({
			gp_url: a,
			onClick: function(m) {
				var o = $("#" + h);
				o.val(m);
				var n = $("#error_msg" + targetdiv[0]);
				var l = o[0];
				if (n.data("tag") === 1) {
					n.hide()
				}
			},
			onReload: function() {
				$("#" + h).val("");
				$("#error_msg").css("display", "none");
				var l = $.jc_getcookie("current_captcha_type")
			},
			onReloading: function() {
				return true
			}
		})
	});
	TouClick.get("touclick-" + TouLocal.getRandCodeName(d)).reload();
	$(".login .touclick-image").attr("src", a)
}

function verifyRandCodeUAM(d, b) {
	if (typeof(b) !== "boolean") {
		showError(d, b);
		return false
	}
	var a = d.value;
	var c = typeof(TouLocal.getErrorMessage) === "function" ? TouLocal.getErrorMessage(d) : login_messages.pleaseClickCaptcha;
	if ("" == a || null == a) {
		showError(d, c, 1);
		return false
	}
	if (!checkRandCodeUAM(d)) {
		c = typeof(TouLocal.getErrorMessage) === "function" ? TouLocal.getErrorMessage(d, false) : login_messages.pleaseClickCaptcha;
		showError(d, c, 1);
		return false
	}
	showError(d).hide();
	return true
}

function checkRandCodeUAM(e) {
	var b = false,
		a = e.value,
		c = "sjrand",
		d = TouClick.get("touclick-" + e.id);
	var f = $.jc_getcookie("uamsession");
	$.ajax({
		url: passport_captcha_check,
		type: "post",
		dataType: "json",
		xhrFields: {
			withCredentials: true
		},
		data: {
			answer: a,
			login_site: "E",
			rand: c
		},
		async: false,
		success: function(g) {
			if (g.result_code == "4") {
				b = true;
				d.success();
				setTimeout(function() {
					if (d.getState() === "success") {
						d.reload()
					}
				}, 3000)
			} else {
				b = false;
				var h = g.result_message;
				d.fail()
			}
		}
	});
	return b
};
var left_ticket_messages = {
	"leftTicketDTO.from_station": "出发站",
	"leftTicketDTO.to_station": "目的站",
	"leftTicketDTO.train_no": "车次",
	"leftTicketDTO.train_date": "出发日",
	back_train_date: "返程日"
};
jQuery.validator.addMethod("checkLoginUserName", function(f, d) {
	var a = false;
	var c = /^(13[0-9])|(14[0-9])|(15[0-9])|(18[0-9])|(17[0-9])\d{8}$/;
	var b = /^[A-Za-z]{1}([A-Za-z0-9]|[_]){0,29}$/;
	var e = /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i;
	if (b.test(f) || e.test(f) || c.test(f)) {
		a = true
	}
	return this.optional(d) || a
}, "wrong username.");
jQuery.validator.addMethod("requiredUserName", function(b, a) {
	if ("用户名／邮箱／手机号" == b) {
		return false
	}
	if (b == null || "" == b) {
		return false
	}
	return true
}, "wrong username.");
jQuery.validator.addMethod("requiredSchoolName", function(b, a) {
	if ("简码／汉字" == b) {
		return false
	}
	if (b == null || "" == b) {
		return false
	}
	return true
}, "wrong schoolname.");
jQuery.validator.addMethod("randCodeRequired", function(b, a) {
	$("#i-ok").css("display", "none");
	return b.length > 0
}, "验证码错误!");
jQuery.validator.addMethod("randCodeFormat", function(c, b) {
	$("#i-ok").css("display", "none");
	var a = /^[a-zA-Z0-9]+$/;
	return this.optional(b) || a.test(c)
}, "验证码错误!");
jQuery.validator.addMethod("randCodeLength", function(b, a) {
	$("#i-ok").css("display", "none");
	return b.length == 4
}, "验证码错误!.");
jQuery.validator.addMethod("integrationCheck", function(b, a) {
	var c = /^\d{6}$/;
	return this.optional(a) || c.test(b)
}, "wrong integrationpassword");
jQuery.validator.addMethod("integrationPwdCheck", function(b, a, c) {
	if ($("#" + c[0]).val() == $("#" + c[1]).val()) {
		return true
	}
	return false
}, "两次输入密码不一致!.");
jQuery.validator.addMethod("checkRandCode", function(c, b, d) {
	var a = true;
	if (c && c.length == 4) {
		$.ajax({
			url: ctx + "passcodeNew/checkRandCodeAnsyn",
			type: "post",
			data: {
				randCode: c,
				rand: d
			},
			async: false,
			success: function(e) {
				if (e.data == "N") {
					a = false;
					$("#i-ok").css("display", "none")
				} else {
					a = true;
					$("#i-ok").css("display", "block")
				}
			}
		})
	} else {
		a = false;
		$("#i-ok").css("display", "none")
	}
	return a
}, "验证码错误!.");
jQuery.validator.addMethod("validateUsersName", function(b, a) {
	return this.optional(a) || /^[A-Za-z]{1}([A-Za-z0-9]|[_]){0,29}$/.test(b)
}, "用户名只能由字母、数字或_组成");
jQuery.validator.addMethod("checkWriteSpace", function(c, b) {
	for (var a = 0; a < c.length; a++) {
		if (c.charCodeAt(a) == 32) {
			return false
		}
	}
	return true
}, "contain writespace");
jQuery.validator.addMethod("validateRandCode", function(b, a) {
	return this.optional(a) || /^[a-zA-Z0-9]+$/.test(b)
}, "验证码错误!.");
jQuery.validator.addMethod("checkPassward", function(c, b, e) {
	var d = true;
	for (var a = 0; a < c.length; a++) {
		if (c.charCodeAt(a) == 39 || c.charCodeAt(a) == 60 || c.charCodeAt(a) == 62) {
			d = false
		}
		if (!d) {
			break
		}
	}
	return this.optional(b) || d
}, "Passward wrong");

function validateSecIdCard(g) {
	var f = 0;
	var a = g;
	var e = {
		11: "北京",
		12: "天津",
		13: "河北",
		14: "山西",
		15: "内蒙",
		21: "辽宁",
		22: "吉林",
		23: "黑龙",
		31: "上海",
		32: "江苏",
		33: "浙江",
		34: "安徽",
		35: "福建",
		36: "江西",
		37: "山东",
		41: "河南",
		42: "湖北",
		43: "湖南",
		44: "广东",
		45: "广西",
		46: "海南",
		50: "重庆",
		51: "四川",
		52: "贵州",
		53: "云南",
		54: "西藏",
		61: "陕西",
		62: "甘肃",
		63: "青海",
		64: "宁夏",
		65: "新疆",
		71: "台湾",
		81: "香港",
		82: "澳门",
		91: "国外"
	};
	if (!/^\d{17}(\d|x)$/i.test(a)) {
		return false
	}
	a = a.replace(/x$/i, "a");
	if (e[parseInt(a.substr(0, 2))] == null) {
		return false
	}
	var c = a.substr(6, 4) + "-" + Number(a.substr(10, 2)) + "-" + Number(a.substr(12, 2));
	var h = new Date(c.replace(/-/g, "/"));
	if (c != (h.getFullYear() + "-" + (h.getMonth() + 1) + "-" + h.getDate())) {
		return false
	}
	for (var b = 17; b >= 0; b--) {
		f += (Math.pow(2, b) % 11) * parseInt(a.charAt(17 - b), 11)
	}
	if (f % 11 != 1) {
		return false
	}
	return true
}

function validateFirIdCard(g) {
	var f = 0;
	var a;
	var e = {
		11: "北京",
		12: "天津",
		13: "河北",
		14: "山西",
		15: "内蒙",
		21: "辽宁",
		22: "吉林",
		23: "黑龙",
		31: "上海",
		32: "江苏",
		33: "浙江",
		34: "安徽",
		35: "福建",
		36: "江西",
		37: "山东",
		41: "河南",
		42: "湖北",
		43: "湖南",
		44: "广东",
		45: "广西",
		46: "海南",
		50: "重庆",
		51: "四川",
		52: "贵州",
		53: "云南",
		54: "西藏",
		61: "陕西",
		62: "甘肃",
		63: "青海",
		64: "宁夏",
		65: "新疆",
		71: "台湾",
		81: "香港",
		82: "澳门",
		91: "国外"
	};
	if (g.length == 15) {
		a = idCardUpdate(g)
	} else {
		a = g
	}
	if (!/^\d{17}(\d|x)$/i.test(a)) {
		return false
	}
	a = a.replace(/x$/i, "a");
	if (e[parseInt(a.substr(0, 2))] == null) {
		return false
	}
	var c = a.substr(6, 4) + "-" + Number(a.substr(10, 2)) + "-" + Number(a.substr(12, 2));
	var h = new Date(c.replace(/-/g, "/"));
	if (c != (h.getFullYear() + "-" + (h.getMonth() + 1) + "-" + h.getDate())) {
		return false
	}
	for (var b = 17; b >= 0; b--) {
		f += (Math.pow(2, b) % 11) * parseInt(a.charAt(17 - b), 11)
	}
	if (f % 11 != 1) {
		return false
	}
	return true
}

function idCardUpdate(g) {
	var b;
	var f = /^(\d){15}$/;
	if (f.test(g)) {
		var e = 0;
		var a = new Array(7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2);
		var d = new Array("1", "0", "X", "9", "8", "7", "6", "5", "4", "3", "2");
		g = g.substr(0, 6) + "19" + g.substr(6, g.length - 6);
		for (var c = 0; c < g.length; c++) {
			e += parseInt(g.substr(c, 1)) * a[c]
		}
		g += d[e % 11];
		b = g
	} else {
		b = "#"
	}
	return b
}
jQuery.validator.addMethod("checkBorth", function(e, c) {
	var b = e;
	if (b == "") {
		return true
	} else {
		var a = b.match(/^(\d{1,4})(-|\/)(\d{1,2})\2(\d{1,2})$/);
		if (a == null) {
			return false
		}
		var f = new Date(a[1], a[3] - 1, a[4]);
		return (f.getFullYear() == a[1] && (f.getMonth() + 1) == a[3] && f.getDate() == a[4])
	}
}, "日期格式不合法");
jQuery.validator.addMethod("byteRangeLength", function(d, b, e) {
	var c = d.length;
	for (var a = 0; a < d.length; a++) {
		if (d.charCodeAt(a) > 127) {
			c++
		}
	}
	return this.optional(b) || (c >= e[0] && c <= e[1])
}, "length wrong");
jQuery.validator.addMethod("checkNameCharBlank", function(c, b, d) {
	var a = d.split("@");
	if ($("#" + a[1]).val() == "") {
		return true
	} else {
		if ($("#" + a[0]).val() == "1" || $("#" + a[0]).val() == "2") {
			return this.optional(b) || /^[a-zA-Z·.．\u3400-\u9FFF]+$/.test(c)
		} else {
			if ($("#" + a[0]).val() == "B") {
				if (/^[-]+$/.test(c)) {
					return false
				}
				return this.optional(b) || /^[a-z A-Z·.．\u3400-\u9FFF\-]+$/.test(c)
			} else {
				if ($("#" + a[0]).val() == "H") {
					if (/^[-]+$/.test(c)) {
						return false
					}
					return this.optional(b) || /^[a-z A-Z·。.．\u3400-\u9FFF-]+$/.test(c)
				} else {
					return this.optional(b) || /^[a-z A-Z·.．\u3400-\u9FFF]+$/.test(c)
				}
			}
		}
	}
}, "wrong name.");
jQuery.validator.addMethod("checkIdValidStr", function(c, b) {
	var a = /^[a-zA-Z0-9\_\-\(\)]+$/;
	return this.optional(b) || (a.test(c))
}, "wrong id");
jQuery.validator.addMethod("isSecIDCard", function(b, a, c) {
	if (!checkIfSecIdCard($(c).val())) {
		return true
	}
	return validateSecIdCard(b)
}, "wrong");

function checkIfSecIdCard(a) {
	if (a == "1") {
		return true
	}
	return false
}

function checkIfFirIdCard(a) {
	if (a == "2") {
		return true
	}
	return false
}

function checkCardForHKorTW(a) {
	if (a == "C" || a == "G") {
		return true
	}
	return false
}
jQuery.validator.addMethod("isFirIDCard", function(b, a, c) {
	if (!checkIfFirIdCard($(c).val())) {
		return true
	}
	return validateFirIdCard(b)
}, "wrong");
jQuery.validator.addMethod("checkHkongMacao", function(c, b, d) {
	if ($(d).val() == "C") {
		var a = /^[HMhm]{1}([0-9]{10}|[0-9]{8})$/;
		return this.optional(b) || (a.test(c))
	} else {
		return true
	}
}, "wrong format.");
jQuery.validator.addMethod("checkTaiw", function(c, a, e) {
	if ($(e).val() == "G") {
		var d = /^[0-9]{8}$/;
		var b = /^[0-9]{10}$/;
		return this.optional(a) || (d.test(c)) || (b.test(c))
	} else {
		return true
	}
}, "wrong format.");
jQuery.validator.addMethod("checkPassport", function(d, b, e) {
	if ($(e).val() == "B") {
		var c = /^[a-zA-Z]{5,17}$/;
		var a = /^[a-zA-Z0-9]{5,17}$/;
		return this.optional(b) || (a.test(d)) || c.test(d)
	} else {
		return true
	}
}, "wrong format.");
jQuery.validator.addMethod("checkWork", function(c, b, d) {
	if ($(d).val() == "H") {
		var a = /^[a-zA-Z]{3}[0-9]{12}$/;
		return this.optional(b) || (a.test(c))
	} else {
		return true
	}
}, "wrong format.");
jQuery.validator.addMethod("isMobile", function(d, b) {
	var c = d.length;
	var a = /^(13[0-9])|(14[0-9])|(15[0-9])|(18[0-9])|(17[0-9])\d{8}$/;
	return this.optional(b) || (c == 11 && a.test(d))
}, "wrong mobile phone ");
jQuery.validator.addMethod("isTelePhone", function(b, a) {
	var c = /(^[0-9]{3,4}\-[0-9]{3,8}$)|(^[0-9]{3,8}$)|(^[0-9]{3,4}\)[0-9]{3,8}$)|(^0{0,1}13[0-9]{9}#)/;
	return this.optional(a) || (c.test(b))
}, "wrong telePhone ");
jQuery.validator.addMethod("illegalChar", function(c, b, e) {
	var d = true;
	if (c.indexOf("$") >= 0) {
		return false
	}
	for (var a = 0; a < c.length; a++) {
		if (c.charCodeAt(a) == 39 || c.charCodeAt(a) == 60 || c.charCodeAt(a) == 62 || c.charCodeAt(a) == 34 || c.charCodeAt(a) == 63) {
			d = false
		}
		if (!d) {
			break
		}
	}
	return this.optional(b) || d
}, "Illegal char wrong");
jQuery.validator.addMethod("isZipCode", function(c, b) {
	var a = /^[0-9]{6}$/;
	return this.optional(b) || (a.test(c))
}, "wrong zipcode");
jQuery.validator.addMethod("isEmail", function(c, a) {
	var b = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
	return this.optional(a) || (b.test(trim(c)))
}, "wrong email");

function replaceChar(b) {
	var a = b.value.replace(/['"<> ?]/g, "");
	b.value = a
}

function checkNameChar1(a) {
	return /^[a-zA-Z0-9\u3400-\u9FFF]+$/.test(a)
}

function trim(a) {
	return a.replace(/(^\s*)|(\s*$)/g, "")
}

function ltrim(a) {
	return a.replace(/(^\s*)/g, "")
}

function rtrim(a) {
	return a.replace(/(\s*$)/g, "")
}
jQuery.validator.addMethod("validateName", function(b, a) {
	return this.optional(a) || /^[a-zA-Z\u3400-\u9FFF0-9\_]+$/.test(b)
}, "wrong username.");
jQuery.validator.addMethod("studentRequired", function(b, a, c) {
	if ($(c).val() == "3") {
		return b && trim(b) != ""
	}
	return true
}, "wrong studentRequired.");
jQuery.validator.addMethod("studentStationRequired", function(b, a, c) {
	if ($(c).val() == "3") {
		return b && trim(b) != "简拼/全拼/汉字" && trim(b) != ""
	}
	return true
}, "wrong studentStationRequired.");
jQuery.validator.addMethod("studentValidateName", function(b, a, c) {
	if ($(c).val() == "3") {
		return this.optional(a) || /^[a-zA-Z\u3400-\u9FFF0-9\_]+$/.test(b)
	}
	return true
}, "wrong username.");
jQuery.validator.addMethod("checkStudentName", function(b, a, c) {
	if ($(c).val() == "3") {
		if ((!b || trim(b) == "" || trim(b) == "简码/汉字")) {
			return false
		}
	}
	return true
}, "wrong username.");
jQuery.validator.addMethod("isQuestionNull", function(b, a, c) {
	if (jQuery.trim(b) != "") {
		if (jQuery.trim($(c[0]).val()) == "customQuestion" && jQuery.trim($(c[1]).val()) == "" || jQuery.trim($(c[0]).val()) == "") {
			return false
		}
	}
	return true
}, "you should input the question");
jQuery.validator.addMethod("isAnswerNull", function(b, a, c) {
	if ((jQuery.trim($(c[0]).val()) == "customQuestion" && jQuery.trim($(c[1]).val()) != "") || (jQuery.trim($(c[0]).val()) != "")) {
		if (jQuery.trim(b) == "") {
			return false
		}
	}
	return true
}, "you should input the answer");

function checkSex(c, b, a) {
	if (!checkSexByCardId(c, b, a)) {
		if (!confirm("性别与身份证中的性别不符，是否继续?")) {
			return false
		} else {
			return true
		}
	} else {
		return true
	}
}

function checkSexByCardId(c, e, a) {
	function b(h, i) {
		var g = null;
		if (i.length == 15) {
			g = i.substring(14, 15)
		} else {
			if (i.length == 18) {
				g = i.substring(16, 17)
			} else {
				return true
			}
		}
		if (g == "x" || g == "X") {
			g = "10"
		}
		var f = parseInt(g);
		var j = f % 2;
		if (j === 0 && h === "F") {
			return true
		} else {
			if (j === 1 && h === "M") {
				return true
			} else {
				return false
			}
		}
	}
	var d = $(a).val();
	if (checkIfSecIdCard($(e).val()) && validateSecIdCard(d)) {
		if (d !== "") {
			return b(c, d)
		} else {
			return true
		}
	} else {
		if (checkIfFirIdCard($(e).val()) && validateFirIdCard(d)) {
			if (d !== "") {
				return b(c, d)
			} else {
				return true
			}
		} else {
			return true
		}
	}
}

function checkBirdDateByCardId(c, e, b) {
	var a = null;
	var d = $(b).val();
	if (checkIfSecIdCard($(e).val()) && d !== "" && validateSecIdCard(d)) {
		a = d.substring(6, 14)
	} else {
		if (checkIfFirIdCard($(e).val()) && d !== "" && validateFirIdCard(d)) {
			if (d.length == 15) {
				a = "19" + d.substring(6, 12)
			} else {
				if (d.length == 18) {
					a = d.substring(6, 14)
				}
			}
		} else {
			return true
		}
	}
	if (c !== "") {
		c = c.replace(/-/g, "");
		if (c != a) {
			return false
		} else {
			return true
		}
	} else {
		return true
	}
}

function checkBirdate(c, b, a) {
	if (!checkBirdDateByCardId(c, b, a)) {
		if (!confirm("出生日期与身份证中的出生日期不符，是否继续?")) {
			return false
		} else {
			return true
		}
	} else {
		return true
	}
}
jQuery.validator.addMethod("checkPwdValidate", function(b, a) {
	return this.optional(a) || /(?![a-z]+$|[0-9]+$|_+$)^[a-zA-Z0-9_]{6,}$/.test(b)
}, "contain writespace");
jQuery.validator.addMethod("checkConfirmPassWard", function(b, a, c) {
	if ($(c).val() != null) {
		return $(c).val() == b
	}
	return true
}, "contain writespace");
jQuery.validator.addMethod("IVR_passwd_format", function(b, a) {
	var c = /^[0-9]{6}$/;
	return this.optional(a) || c.test(b)
}, "验证码错误!.");
jQuery.validator.addMethod("checkStation", function(b, a) {
	if ((!b || trim(b) == "" || trim(b) == "简拼/全拼/汉字" || trim(b) == "简拼/全拼/汉字或↑↓")) {
		return false
	}
	return true
}, "wrong username.");
jQuery.validator.addMethod("checkAnsyUserName", function(e, c, f) {
	var b = f[0];
	var d = $("#" + f[1]).val();
	var a = true;
	$.ajax({
		url: b + "?user_name=" + e,
		type: "get",
		async: false,
		success: function(g, h) {
			if (g.data == true) {
				a = false
			} else {
				a = true
			}
		},
		error: function(g, i, h) {
			a = false
		}
	});
	return a
}, "wrong cardNo");

function checkPwdRank(e, a, d) {
	var b = $(e);
	var c = b.val();
	if (c.length <= 6 || new RegExp("^[a-zA-Z]{6,}$").test(c) || new RegExp("^[0-9]{6,}$").test(c) || new RegExp("^[_]{6,}$").test(c)) {
		$("#" + a).attr("title", "危险");
		$("#" + d).html("危险");
		$("#" + a).removeClass("rank-a");
		$("#" + a).removeClass("rank-b");
		$("#" + a).removeClass("rank-c");
		$("#" + a).addClass("rank-a")
	} else {
		if (c.length > 6 && new RegExp("[a-zA-Z]").test(c) && new RegExp("[0-9]").test(c) && new RegExp("[_]").test(c)) {
			$("#" + a).attr("title", "安全");
			$("#" + d).html("安全");
			$("#" + a).removeClass("rank-a");
			$("#" + a).removeClass("rank-b");
			$("#" + a).removeClass("rank-c");
			$("#" + a).addClass("rank-c")
		} else {
			$("#" + a).attr("title", "一般");
			$("#" + d).html("一般");
			$("#" + a).removeClass("rank-a");
			$("#" + a).removeClass("rank-b");
			$("#" + a).removeClass("rank-c");
			$("#" + a).addClass("rank-b")
		}
	}
}
Array.prototype.unique = function() {
	var b = {},
		a = this.length;
	for (var c = 0; c < a; c++) {
		if (typeof b[this[c]] == "undefined") {
			b[this[c]] = 1
		}
	}
	this.length = 0;
	a = 0;
	for (var c in b) {
		this[a++] = c
	}
	return this
};

function checkSearchPwdRank(h, c, g) {
	var e = $(h);
	var f = e.val();
	if (f.length < 6) {
		$("#" + c).attr("title", "危险");
		$("#" + g).html("危险");
		$("#" + c).removeClass("rank-a");
		$("#" + c).removeClass("rank-b");
		$("#" + c).removeClass("rank-c");
		$("#" + c).addClass("rank-a")
	} else {
		var a = [];
		for (var b = 0; b < 6; b++) {
			a.push(f.charAt(b))
		}
		a = a.unique();
		var d = a.length;
		if (d == 1) {
			$("#" + c).attr("title", "危险");
			$("#" + g).html("危险");
			$("#" + c).removeClass("rank-a");
			$("#" + c).removeClass("rank-b");
			$("#" + c).removeClass("rank-c");
			$("#" + c).addClass("rank-a")
		} else {
			if (d > 1 && d < 5) {
				$("#" + c).attr("title", "一般");
				$("#" + g).html("一般");
				$("#" + c).removeClass("rank-a");
				$("#" + c).removeClass("rank-b");
				$("#" + c).removeClass("rank-c");
				$("#" + c).addClass("rank-b")
			} else {
				$("#" + c).attr("title", "安全");
				$("#" + g).html("安全");
				$("#" + c).removeClass("rank-a");
				$("#" + c).removeClass("rank-b");
				$("#" + c).removeClass("rank-c");
				$("#" + c).addClass("rank-c")
			}
		}
	}
}
jQuery.validator.addMethod("checkDetailAddress", function(b, a) {
	return this.optional(a) || /^[0-9a-zA-Z\u3400-\u9FFF\#]+$/.test(b)
}, "wrong name.");
jQuery.validator.addMethod("checkAddressName", function(b, a) {
	if (/^[-]+$/.test(b)) {
		return false
	}
	return this.optional(a) || /^[a-z A-Z·.．\u3400-\u9FFF\-]+$/.test(b) || /^[a-zA-Z·.．\u3400-\u9FFF]+$/.test(b)
}, "wrong name.");
jQuery.validator.addMethod("checkAddressSelect", function(b, a) {
	if ("" == b) {
		return false
	}
	if (b) {
		return true
	}
	return this.optional(a)
}, "wrong name.");
var login_messages = {
	randCodeError: "验证码错误!",
	randCodeExpired: "验证码失效",
	randCodeLentgh: "验证码长度为4位!",
	randCodeFormat: "验证码只能由数字或字母组成!",
	randCodeEmpty: "验证码不能为空!",
	userNameEmpty: "登录名必须填写!",
	userNameFormat: "登录名格式不正确，请重新输入!",
	passwordEmpty: "密码必须填写,且不少于6位!",
	passwordLength: "密码长度不能少于6位!",
	pleaseClickCaptcha: "请点击验证码",
	pleaseClickLeftCaptcha: "请点击左侧验证码",
	pleaseClickCaptchaRight: "请点击正确的验证码",
	pleaseClickBottomCaptcha: "请点击下方验证码",
	loginError: "当前访问用户过多,请稍候重试!",
	submitAfterVerify: "提交",
	pleaseClickSubmitButtonAfterClick: "pleaseClickSubmitButtonAfterClick",
	leftTicketOrderNoteMessage: '点击"提交"按钮获取验证码',
	leftTicketOrderClickCallbackNoteMessage: '完成选择后，继续点击下方橙色"提交"按钮提交订单',
	leftTicketOrderShowCallbackNoteMessage: "按照提示点击选择所有的图片",
	leftTicketOrderHiddenCallbackNoteMessage: '点击"提交"按钮获取验证码',
	getCaptchaByClick: "点击获取验证码"
};

function Marquee(a) {
	if (a == null || a == "") {
		return
	}
	this.ID = document.getElementById(a.ID);
	if (!this.ID) {
		this.id = -1;
		return
	}
	this.Direction = this.Width = this.Height = this.DelayTime = this.WaitTime = this.CTL = this.StartID = this.Stop = this.MouseOver = 0;
	this.Step = 1;
	this.Timer = 30;
	this.DirectionArray = {
		top: 0,
		up: 0,
		bottom: 1,
		down: 1,
		left: 2,
		right: 3
	};
	if (typeof a.Direction == "number" && a.Direction) {
		this.Direction = a.Direction
	}
	if (typeof a.Direction == "string" && a.Direction) {
		this.Direction = this.DirectionArray[a.Direction.toString().toLowerCase()]
	}
	if (typeof a.Step == "number" && a.Step) {
		this.Step = a.Step
	}
	if (typeof a.Width == "number" && a.Width) {
		this.Width = a.Width
	}
	if (typeof a.Height == "number" && a.Height) {
		this.Height = a.Height
	}
	if (typeof a.Timer == "number" && a.Timer) {
		this.Timer = a.Timer
	}
	if (typeof a.DelayTime == "number" && a.DelayTime) {
		this.DelayTime = a.DelayTime
	}
	if (typeof a.WaitTime == "number" && a.WaitTime) {
		this.WaitTime = a.WaitTime
	}
	if (typeof a.ScrollStep == "number" && a.ScrollStep) {
		this.ScrollStep = a.ScrollStep
	}
	this.ID.style.overflow = this.ID.style.overflowX = this.ID.style.overflowY = "hidden";
	this.ID.noWrap = true;
	this.IsNotOpera = (navigator.userAgent.toLowerCase().indexOf("opera") == -1);
	this.Start()
}
Marquee.prototype.Start = function() {
	if (this.ID == -1) {
		return
	}
	if (this.Width == 0) {
		this.Width = parseInt(this.ID.style.width)
	}
	if (this.Height == 0) {
		this.Height = parseInt(this.ID.style.height)
	}
	if (this.Timer < 20) {
		this.Timer = 20
	}
	if (this.WaitTime < 800) {
		this.WaitTime = 800
	}
	this.HalfWidth = Math.round(this.Width / 2);
	this.HalfHeight = Math.round(this.Height / 2);
	this.BakStep = this.Step;
	this.ID.style.width = this.Width + "px";
	this.ID.style.height = this.Height + "px";
	if (typeof this.ScrollStep != "number") {
		this.ScrollStep = this.Direction > 1 ? this.Width : this.Height
	}
	var d = "<table cellspacing='0' cellpadding='0' style='border-collapse:collapse;display:inline;'><tr><td noWrap=true style='white-space: nowrap;word-break:keep-all;padding-right:100px;'>MSCLASS_TEMP_HTML</td><td noWrap=true style='white-space: nowrap;word-break:keep-all;'>MSCLASS_TEMP_HTML</td></tr></table>";
	var b = "<table cellspacing='0' cellpadding='0' style='border-collapse:collapse;'><tr><td>MSCLASS_TEMP_HTML</td></tr><tr><td>MSCLASS_TEMP_HTML</td></tr></table>";
	var e = this;
	e.tempHTML = e.ID.innerHTML;
	if (e.Direction <= 1) {
		e.ID.innerHTML = b.replace(/MSCLASS_TEMP_HTML/g, e.ID.innerHTML)
	} else {
		if (e.ScrollStep == 0 && e.DelayTime == 0) {
			e.ID.innerHTML += e.ID.innerHTML
		} else {
			e.ID.innerHTML = d.replace(/MSCLASS_TEMP_HTML/g, e.ID.innerHTML)
		}
	}
	var f = this.Timer;
	var a = this.DelayTime;
	var c = this.WaitTime;
	e.StartID = function() {
		e.Scroll()
	};
	e.Continue = function() {
		if (e.MouseOver == 1) {
			setTimeout(e.Continue, a)
		} else {
			clearInterval(e.TimerID);
			e.CTL = e.Stop = 0;
			e.TimerID = setInterval(e.StartID, f)
		}
	};
	e.Pause = function() {
		e.Stop = 1;
		clearInterval(e.TimerID);
		setTimeout(e.Continue, a)
	};
	e.Begin = function() {
		e.ClientScroll = e.Direction > 1 ? e.ID.scrollWidth / 2 : e.ID.scrollHeight / 2;
		if ((e.Direction <= 1 && e.ClientScroll <= e.Height + e.Step) || (e.Direction > 1 && e.ClientScroll <= e.Width + e.Step)) {
			e.ID.innerHTML = e.tempHTML;
			delete(e.tempHTML);
			return
		}
		delete(e.tempHTML);
		e.TimerID = setInterval(e.StartID, f);
		if (e.ScrollStep < 0) {
			return
		}
		e.ID.onmousemove = function(g) {
			if (e.ScrollStep == 0 && e.Direction > 1) {
				var g = g || window.event;
				if (window.event) {
					if (e.IsNotOpera) {
						e.EventLeft = g.srcElement.id == e.ID.id ? g.offsetX - e.ID.scrollLeft : g.srcElement.offsetLeft - e.ID.scrollLeft + g.offsetX
					} else {
						e.ScrollStep = null;
						return
					}
				} else {
					e.EventLeft = g.layerX - e.ID.scrollLeft
				}
				e.Direction = e.EventLeft > e.HalfWidth ? 3 : 2;
				e.AbsCenter = Math.abs(e.HalfWidth - e.EventLeft);
				e.Step = Math.round(e.AbsCenter * (e.BakStep * 2) / e.HalfWidth)
			}
		};
		e.ID.onmouseover = function() {
			if (e.ScrollStep == 0) {
				return
			}
			e.MouseOver = 1;
			clearInterval(e.TimerID)
		};
		e.ID.onmouseout = function() {
			if (e.ScrollStep == 0) {
				if (e.Step == 0) {
					e.Step = 1
				}
				return
			}
			e.MouseOver = 0;
			if (e.Stop == 0) {
				clearInterval(e.TimerID);
				e.TimerID = setInterval(e.StartID, f)
			}
		}
	};
	setTimeout(e.Begin, c)
};
Marquee.prototype.Scroll = function() {
	switch (this.Direction) {
		case 0:
			this.CTL += this.Step;
			if (this.CTL >= this.ScrollStep && this.DelayTime > 0) {
				this.ID.scrollTop += this.ScrollStep + this.Step - this.CTL;
				this.Pause();
				return
			} else {
				if (this.ID.scrollTop >= this.ClientScroll) {
					this.ID.scrollTop -= this.ClientScroll
				}
				this.ID.scrollTop += this.Step
			}
			break;
		case 1:
			this.CTL += this.Step;
			if (this.CTL >= this.ScrollStep && this.DelayTime > 0) {
				this.ID.scrollTop -= this.ScrollStep + this.Step - this.CTL;
				this.Pause();
				return
			} else {
				if (this.ID.scrollTop <= 0) {
					this.ID.scrollTop += this.ClientScroll
				}
				this.ID.scrollTop -= this.Step
			}
			break;
		case 2:
			this.CTL += this.Step;
			if (this.CTL >= this.ScrollStep && this.DelayTime > 0) {
				this.ID.scrollLeft += this.ScrollStep + this.Step - this.CTL;
				this.Pause();
				return
			} else {
				if (this.ID.scrollLeft >= this.ClientScroll) {
					this.ID.scrollLeft -= this.ClientScroll
				}
				this.ID.scrollLeft += this.Step
			}
			break;
		case 3:
			this.CTL += this.Step;
			if (this.CTL >= this.ScrollStep && this.DelayTime > 0) {
				this.ID.scrollLeft -= this.ScrollStep + this.Step - this.CTL;
				this.Pause();
				return
			} else {
				if (this.ID.scrollLeft <= 0) {
					this.ID.scrollLeft += this.ClientScroll
				}
				this.ID.scrollLeft -= this.Step
			}
			break
	}
};