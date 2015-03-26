<?php
/**
 * @file
 * A template for the buy tickets box.
 */
?>

<div class="buy-tickets-wrapper <?php print $wrapper_classes; ?>">
  <div class="text-center">
    <i class="icon fa fa-ticket fa-5x"></i>
  </div>

  <div class="page-header">
    <h2 class="text-center">Buy Tickets</h2>
  </div>
  
  <p class="lead">Tickets will be on sale soon!</p>
  <?php // TODO: Remove this hacky line soon. ?>
  <p>&nbsp;</p>
  
  <!--
  <div class="table-responsive">
    <table class="table ticket-table">
      <tbody>
        <tr>
          <td>General Admission</td>
          <td>
            <a href="/%23" class="btn btn-danger btn-sm" disabled="disabled">
              <del>$40.00</del>
            </a>
          </td>
        </tr>
        <tr>
          <td>Designated Driver</td>
          <td>
            <a href="/%23" class="btn btn-danger btn-sm" disabled="disabled">
              <del>$10.00</del>
            </a>
          </td>
        </tr>
      </tbody>
    </table>
  </div>
  -->
</div>

