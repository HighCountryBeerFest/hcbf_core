<?php
/**
 * @file
 * Page template for /sponsors
 */
?>

<div class="sponsors-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-sm-12 col-lg-8">
        <div class="container-fluid">
          <?php if (empty($sponsors)): ?>
            <h1>We're announcing sponsors soon!</h1>
          <?php else: ?>
            <?php foreach ($sponsors as $level => $level_sponsors): ?>

              <div class="row">
                <div class="col-xs-12">
                  <div class="page-header">
                    <h2><?php print $level; ?> Sponsors</h2>
                  </div>
                </div>
              </div>

              <?php $level_sponsors = array_chunk($level_sponsors, 2); ?>
              <?php foreach ($level_sponsors as $sponsor): ?>
                <div class="row sponsors-row">
                  <?php foreach ($sponsor as $s): ?>
                    <div class="col-sm-12 col-sm-6">
                      <div class="text-center">
                        <?php print $s['logo']; ?>
                      </div>
                      <h2 class="text-center">
                        <?php print l($s['name'], $s['link']); ?>
                      </h2>
                    </div>
                  <?php endforeach; ?>
                </div>
              <?php endforeach; ?>

            <?php endforeach; ?>
          <?php endif; ?>
        </div>
      </div>
      <div class="col-sm-12 col-lg-4">
        <div class="container-fluid">
          <div class="col-sm-12 col-md-6 col-lg-12">
            <?php print theme('hcbf_sponsor_registration'); ?>
          </div>
          <div class="col-sm-12 col-sm-6 col-lg-12">
            <?php print theme('hcbf_festival_tickets'); ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
