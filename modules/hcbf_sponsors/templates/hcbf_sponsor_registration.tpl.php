<?php
/**
 * @file
 * A template for the sponsor registration box.
 */
?>

<div class="register-sponsor-wrapper <?php print $classes; ?>">
  <h1 class="heading text-center">Do you want to be a sponsor?</h1>
  <p class="lead text-center">
    We have plenty of sponsorship opportunities, contact us and we'll let you know how you can help out.
  </p>
  <p class="text-center">
    <a href="/sponsors/register"
       class="btn-success btn btn-lg"
       data-ga-event
       data-ga-category="sponsor_link_click"
       data-ga-label="sponsor"
       data-ga-action="register">
      I'd like to sponsor the Beer Fest
    </a>
  </p>
  <p>&nbsp;</p>
</div>
