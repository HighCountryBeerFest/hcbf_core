<div class="sponsors">
  <h2>Current sponsors</h2>
  <table>
    <thead>
      <tr>
        <th>Name</th>
        <th colspan="3">&nbsp;</th>
      </tr>
    </thead>
    <tbody>

      <?php foreach ($sponsors as $sponsor): ?>
      <tr>
        <tr>
          <td><?php print $sponsor['name']; ?></td>
          <td><?php //print $sponsor['view']; ?></td>
          <td><?php //print $sponsor['edit']; ?></td>
          <td><?php //print $sponsor['delete']; ?></td>
        </tr>
      </tr>
      <?php endforeach; ?>

  </table>
</div>

