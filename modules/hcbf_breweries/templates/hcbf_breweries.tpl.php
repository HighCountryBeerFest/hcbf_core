<?php
/**
 * @file
 * A page that displays listings of all products
 */
?>

<div class="breweries-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-sm-6 col-lg-8">
        <div class="container-fluid">

          <?php foreach ($breweries as $breweries_row) { ?>
            <div class="row brewery-row">
              <?php foreach ($breweries_row as $brewery) { ?>
                <div class="col-sm-12 col-md-4">
                  <?php print render($brewery['logo']); ?>
                  <?php print render($brewery['title']); ?>
                  <?php print render($brewery['location']); ?>
                </div>
              <?php }; ?>
            </div>
          <?php }; ?>

        </div>
      </div>
      <div class="col-xs-12 col-sm-6 col-lg-4">
        <?php print theme('hcbf_breweries_on_sale', array('classes' => 'well')); ?>
      </div>
    </div>
  </div>
</div>

