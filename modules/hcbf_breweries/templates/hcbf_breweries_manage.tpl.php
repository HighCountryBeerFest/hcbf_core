<div class="breweries">
  <h2>Current breweries</h2>

  <?php if (empty($breweries)): ?>
    <h3>There are no breweries signed up yet.</h3>
  <?php else: ?>
    <table>
      <thead>
        <tr>
          <th>Name</th>
          <th>Location</th>
          <th>&nbsp;</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($breweries as $brewery): ?>
        <tr>
          <tr>
            <td><?php print l($brewery['name'], 'node/' . $brewery['nid']); ?></td>
            <td><?php print $brewery['location']; ?></td>
            <td><?php print l(t('Edit'), 'node/' . $brewery['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/breweries'))); ?></td>
          </tr>
        </tr>
        <?php endforeach; ?>
    </table>
  <?php endif; ?>

  <h2>All breweries</h2>

  <?php if (empty($all_breweries)): ?>
    <h3>There are no breweries signed up yet.</h3>
  <?php else: ?>
    <table>
      <thead>
        <tr>
          <th>Name</th>
          <th>Location</th>
          <th>&nbsp;</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($all_breweries as $brewery): ?>
        <tr>
          <tr>
            <td><?php print l($brewery['name'], 'node/' . $brewery['nid']); ?></td>
            <td><?php print $brewery['location']; ?></td>
            <td><?php print l(t('Edit'), 'node/' . $brewery['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/breweries'))); ?></td>
          </tr>
        </tr>
        <?php endforeach; ?>
    </table>
  <?php endif; ?>
  <ul class="action-links">
    <li><?php print l(t('Add a brewery'), 'node/add/hcbf-brewery'); ?></li>
  </ul>

</div>
