<div class="volunteer-manage-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <div class="table-responsive">
          <table class="table">
            <thead>
              <tr>
                <th>Name</th>
                <th>Phone</th>
                <th>Accepted</th>
                <th>Shift</th>
                <th>Job</th>
                <th>&nbsp;</th>
                <th>&nbsp;</th>
                <th>&nbsp;</th>
                <th>&nbsp;</th>
              </tr>
            </thead>
            <tbody>
              <?php foreach ($volunteers as $volunteer) { ?>
                <tr class="<?php print $volunteer['row_class']; ?>">
                  <td><?php print render($volunteer['name']); ?></td>
                  <td><?php print render($volunteer['phone']); ?></td>
                  <td><?php print render($volunteer['approved']); ?></td>
                  <td><?php print render($volunteer['shift']); ?></td>
                  <td><?php print render($volunteer['job']); ?></td>
                  <td><?php print render($volunteer['email']); ?></td>
                  <td><?php print render($volunteer['view']); ?></td>
                  <td><?php print render($volunteer['edit']); ?></td>
                  <td><?php print render($volunteer['delete']); ?></td>
                </tr>
              <?php }; ?>
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>
</div>
