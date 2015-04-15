<div class="music">
  <h2>Current music</h2>

  <?php if (empty($music)): ?>
    <h3>There are no music signed up yet.</h3>
  <?php else: ?>
    <table>
      <thead>
        <tr>
          <th>Name</th>
          <th>&nbsp;</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($music as $band): ?>
        <tr>
          <tr>
            <td><?php print l($band['title'], 'node/' . $band['nid']); ?></td>
            <td><?php print l(t('Edit'), 'node/' . $band['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/music'))); ?></td>
          </tr>
        </tr>
        <?php endforeach; ?>
    </table>
  <?php endif; ?>

  <h2>All music</h2>

  <?php if (empty($all_music)): ?>
    <h3>There are no music signed up yet.</h3>
  <?php else: ?>
    <table>
      <thead>
        <tr>
          <th>Name</th>
          <th>&nbsp;</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($all_music as $band): ?>
        <tr>
          <tr>
            <td><?php print l($band['title'], 'node/' . $band['nid']); ?></td>
            <td><?php print l(t('Edit'), 'node/' . $band['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/music'))); ?></td>
          </tr>
        </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  <?php endif; ?>
  <ul class="action-links">
    <li><?php print l(t('Add a band'), 'node/add/hcbf-band'); ?></li>
  </ul>

</div>

