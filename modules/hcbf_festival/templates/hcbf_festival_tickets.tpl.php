<?php
/**
 * @file
 * A template for the buy tickets box.
 */
?>

<div class="buy-tickets-wrapper">
  <div class="text-center">
    <i class="icon fa fa-ticket fa-5x"></i>
  </div>

  <div class="page-header">
    <h2 class="text-center">Buy Tickets</h2>
  </div>
  
  <?php if (variable_get('hcbf_core_on_sale', 0) != 1): ?>
    <p class="lead text-center">Tickets will be on sale soon!</p>
  <?php else: ?>
    <div class="table-responsive">
      <table class="table ticket-table">
        <tbody>
          <tr>
            <td>General Admission</td>
            <td>
              <a href="<?php print variable_get('hcbf_core_regular_ticket_link', '#'); ?>" class="btn btn-success btn-sm">
                $<?php print variable_get('hcbf_core_regular_ticket_price', '40.00'); ?>
              </a>
            </td>
          </tr>
          <tr>
            <td>Designated Driver</td>
            <td>
              <a href="<?php print variable_get('hcbf_core_dd_ticket_link', '#'); ?>" class="btn btn-success btn-sm">
                $<?php print variable_get('hcbf_core_dd_ticket_price', '10.00'); ?>
              </a>
            </td>
          </tr>
        </tbody>
      </table>
    </div>
  <?php endif; ?>

  <?php // TODO: Remove this hacky line soon. ?>
  <p>&nbsp;</p>
  
</div>

