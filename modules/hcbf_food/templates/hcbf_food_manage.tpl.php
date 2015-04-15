<?php if (!empty($food)): ?>
<div class="food">
  <h2>Current food</h2>
  <table>
    <thead>
      <tr>
        <th>Name</th>
        <th>&nbsp;</th>
      </tr>
    </thead>
    <tbody>
      <?php foreach ($food as $band): ?>
      <tr>
        <tr>
          <td><?php print l($band['title'], 'node/' . $band['nid']); ?></td>
          <td><?php print l(t('Edit'), 'node/' . $band['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/food'))); ?></td>
        </tr>
      </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
</div>
<?php endif; ?>

<div class="all-food">
  <h2>All food</h2>

  <?php if (empty($all_food)): ?>
    <h3>There are no food signed up yet.</h3>
  <?php else: ?>
    <table>
      <thead>
        <tr>
          <th>Name</th>
          <th>&nbsp;</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($all_food as $band): ?>
        <tr>
          <tr>
            <td><?php print l($band['title'], 'node/' . $band['nid']); ?></td>
            <td><?php print l(t('Edit'), 'node/' . $band['nid'] . '/edit', array('query' => array('destination' => 'admin/config/hcbf/food'))); ?></td>
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


