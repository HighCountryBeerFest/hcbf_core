<?php
/**
 * @file
 * A page that displays the food vendors at the Beer Fest.
 */
?>

<div class="food-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-sm-6 col-lg-8">
        <div class="container-fluid">
          <?php foreach ($foods as $food) { ?>
            <div class="row">
              <div class="col-xs-12">
                <?php print render($food['title']); ?>
              </div>
            </div>
            <div class="row">
              <div class="col-xs-12 col-sm-3">
                <?php print render($food['image']); ?>
                <p><?php print render($food['website']); ?></p>
              </div>
              <div class="col-xs-12 col-sm-9">
                <?php print render($food['description']); ?>
              </div>
            </div>
          <?php }; ?>
        </div>
      </div>
      <div class="col-xs-12 col-sm-6 col-lg-4">
        <?php print theme('hcbf_breweries_on_sale', array('wrapper_classes' => 'well')); ?>
      </div>
    </div>
  </div>
</div>

