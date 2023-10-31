/* $(document).ready(function () {
  $("ul.navbar-nav > li").click(function (e) {
   $("ul.navbar-nav > li").removeClass("active");
   $(this).addClass("active");
    });
}); */

$(document).ready(function () {
  $("ul.navbar-nav > li > a").click(
    function (e) {
      $("ul.navbar-nav > li").removeClass(
        "active");
      $("ul.navbar-nav > li > a").css(
        "color", "");

      $(this).addClass("active");
      $(this).css("color", "#FF7848");
  });
});