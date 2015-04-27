(function($){
  Drupal.behaviors.donations_thermometer = {
    attach: function(context, settings) {
      $.gauge = {

        targetHeight : 0,
        progressMeter : new Object(),

        init : function() {
          if (!document.getElementById) {
            return false;
          }
          this.resetValue();
          this.animateGauge();
        },

        resetValue : function() {
          if (document.getElementById("campaign-progress-current"))) {
            return false;
          }
          this.progressMeter = document.getElementById("campaign-progress-current");
          this.targetHeight = this.progressMeter.offsetHeight;
          this.progressMeter.style.height = "0px";
        },

        animateGauge : function(){
          var currHeight = this.progressMeter.offsetHeight;

          if (currHeight == this.targetHeight){
          }

          else {
            var interval = Math.ceil((this.targetHeight - currHeight) / 10);
            this.progressMeter.style.height = currHeight + interval + "px";
            setTimeout("jQuery.gauge.animateGauge()",30);
          }
        }
      };
      
      $.gauge.init();
    }
    
  };
})(jQuery);