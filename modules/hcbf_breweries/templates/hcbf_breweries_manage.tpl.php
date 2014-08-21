<div class="brewery-manage-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <div class="table-responsive">
          <table class="table">
            <thead>
              <tr>
                <th>Name</th>
                <th>City</th>
                <th>State</th>
                <th>&nbsp;</th>
                <th>&nbsp;</th>
                <th>&nbsp;</th>
              </tr>
            </thead>
            <tbody>
              <?php foreach ($breweries as $brewery) { ?>
                <tr class="<?php print $brewery['row_class']; ?>">
                  <td><?php print render($brewery['name']); ?></td>
                  <td><?php print render($brewery['city']); ?></td>
                  <td><?php print render($brewery['state']); ?></td>
                  <td><?php print render($brewery['view']); ?></td>
                  <td><?php print render($brewery['edit']); ?></td>
                  <td><?php print render($brewery['delete']); ?></td>
                </tr>
              <?php }; ?>
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>
</div>
