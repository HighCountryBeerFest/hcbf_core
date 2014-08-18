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

          <div class="row">
            <div class="col-xs-12">
              <div class="page-header">
                <h2>Our Imperial Stout level sponsors</h2>
              </div>
            </div>
          </div>
          <div class="row sponsors-row">
            <?php foreach ($level_4_sponsors as $sponsors_row) { ?>
              <?php foreach ($sponsors_row as $sponsor) { ?>
                <div class="col-sm-12 col-sm-6">
                  <?php print render($sponsor['logo']); ?>
                  <?php print render($sponsor['title']); ?>
                </div>
              <?php }; ?>
            <?php }; ?>
          </div>

          <div class="row">
            <div class="col-xs-12">
              <div class="page-header">
                <h2>Our Double IPA level sponsors</h2>
              </div>
            </div>
          </div>
          <div class="row sponsors-row">
            <?php foreach ($level_3_sponsors as $sponsors_row) { ?>
              <?php foreach ($sponsors_row as $sponsor) { ?>
                <div class="col-sm-4">
                  <?php print render($sponsor['logo']); ?>
                  <?php print render($sponsor['title']); ?>
                </div>
              <?php }; ?>
            <?php }; ?>
          </div>

          <div class="row">
            <div class="col-xs-12">
              <div class="page-header">
                <h2>Our Pale Ale level sponsors</h2>
              </div>
            </div>
          </div>
          <div class="row sponsors-row">
            <?php foreach ($level_2_sponsors as $sponsors_row) { ?>
              <?php foreach ($sponsors_row as $sponsor) { ?>
                <div class="col-sm-4">
                  <?php print render($sponsor['logo']); ?>
                  <?php print render($sponsor['title']); ?>
                </div>
              <?php }; ?>
            <?php }; ?>
          </div>

          <div class="row">
            <div class="col-xs-12">
              <div class="page-header">
                <h2>Our Session Ale level sponsors</h2>
              </div>
            </div>
          </div>
          <div class="row sponsors-row">
            <?php foreach ($level_1_sponsors as $sponsors_row) { ?>
              <?php foreach ($sponsors_row as $sponsor) { ?>
                <div class="col-sm-4">
                  <?php print render($sponsor['logo']); ?>
                  <?php print render($sponsor['title']); ?>
                </div>
              <?php }; ?>
            <?php }; ?>
          </div>

        </div>
      </div>
      <div class="col-sm-12 col-lg-4">
        <div class="container-fluid">
          <div class="col-sm-12 col-md-6 col-lg-12">
            <?php print render(hcbf_register_sponsor_box(array(), array('well'))); ?>
          </div>
          <div class="col-sm-12 col-sm-6 col-lg-12">
            <?php print render(hcbf_buy_tickets_box(array('well'))); ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>

