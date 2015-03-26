<?php
/**
 * @file
 * A template for the brewery registration box.
 */
?>

<div class="register-brewery-wrapper">
  <h1 class="heading text-center">Want to serve your beer?</h1>
  <?php if (variable_get('hcbf_breweries_active', 0) == 1): ?>
    <p class="lead text-center">
      We'd love to have your beer! We're looking for craft breweries who want to participate in this year's High Country Beer Fest.
    </p>
    <p class="text-center">
      <a href="/breweries/register" class="btn-success btn btn-lg">
        I'd like to register my brewery
      </a>
    </p>
  <?php else: ?>
    <p class="lead text-center">We're not accepting brewery registrations at the moment, check back soon!</p>
  <?php endif; ?>
</div>
