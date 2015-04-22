<?php
/**
 * @file
 * A page that displays the musical acts at the Beer Fest.
 */
?>

<div class="music-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-sm-6 col-lg-8">
        <div class="container-fluid">

          <?php if (empty($bands)): ?>
            <h1>We're announcing music soon!</h1>
          <?php endif; ?>

          <?php foreach ($bands as $band) { ?>
            <div class="row">
              <div class="col-xs-12">
                <?php print render($band['title']); ?>
              </div>
            </div>
            <div class="row">
              <div class="col-xs-12 col-sm-3">
                <?php print render($band['image']); ?>
                <p><?php print render($band['website']); ?></p>
              </div>
              <div class="col-xs-12 col-sm-9">
                <?php print render($band['description']); ?>
              </div>
            </div>
          <?php }; ?>

        </div>
      </div>
      <div class="col-xs-12 col-sm-6 col-lg-4">
        <?php print theme('hcbf_festival_tickets'); ?>
      </div>
    </div>
  </div>
</div>

