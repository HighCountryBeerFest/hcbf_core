<div class="sponsors">
  <h2>Current sponsors</h2>
  <?php if (empty($sponsors)): ?>
    <h3>There are no sponsors signed up yet.</h3>
  <?php else: ?>
    <?php foreach ($sponsors as $level => $level_sponsors): ?>
      <h4><?php print $level; ?></h4>
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>&nbsp;</th>
          </tr>
        </thead>
        <tbody>
        <?php foreach ($level_sponsors as $sponsor): ?>
          <tr>
            <tr>
              <td><?php print $sponsor['name']; ?></td>
              <td><?php print l(t('Edit'), 'node/' . $sponsor['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/sponsors'))); ?></td>
            </tr>
          </tr>
        <?php endforeach; ?>
        </tbody>
      </table>
    <?php endforeach; ?>
  <?php endif; ?>

  <h2>All sponsors</h2>
  <?php if (empty($all_sponsors)): ?>
    <h3>There are no sponsors signed up yet.</h3>
  <?php else: ?>
    <?php foreach ($all_sponsors as $level => $level_sponsors): ?>
      <h4><?php print $level; ?></h4>
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>&nbsp;</th>
          </tr>
        </thead>
        <tbody>
        <?php foreach ($level_sponsors as $sponsor): ?>
          <tr>
            <tr>
              <td><?php print $sponsor['name']; ?></td>
              <td><?php print l(t('Edit'), 'node/' . $sponsor['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/sponsors'))); ?></td>
            </tr>
          </tr>
        <?php endforeach; ?>
        </tbody>
      </table>
    <?php endforeach; ?>
  <?php endif; ?>
  <ul class="action-links">
    <li><?php print l(t('Add a sponsor'), 'node/add/hcbf-sponsor'); ?></li>
  </ul>

</div>
