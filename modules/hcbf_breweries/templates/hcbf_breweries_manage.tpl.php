<div class="breweries">
  <h2>Current breweries</h2>
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
</div>
