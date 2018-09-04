function interpsurf(z, method)
  if nargin < 2
    method = 'linear';
  end
  [n, m] = size(z);
  [x, y] = meshgrid(1:m,1:n);         % low-res grid
  [x2,y2] = meshgrid(1:.1:m,1:.1:n);  % high-res grid
  z2 = interp2(x,y,z, x2,y2, method); % interpolate up
  % Draw the faces with no edges using the high-res grid
  f = surf(x2,y2,z2);
  f.EdgeColor = 'none';
  f.FaceColor = 'interp';
  f.FaceLighting = 'gouraud';
  hold on
  % Add the column edges using a mix of low-res and high-res
  [x3,y3] = meshgrid(1:m,1:.1:n);
  z3 = interp2(x,y,z, x3,y3, method);
  c = surf(x3,y3,z3);
  c.FaceColor = 'none';
  c.MeshStyle = 'column';
  % Add the row edges
  [x3,y3] = meshgrid(1:.1:m,1:n);
  z3 = interp2(x,y,z, x3,y3, method);
  r = surf(x3,y3,z3);
  r.FaceColor = 'none';
  r.MeshStyle = 'row';
  % Add markers at the original points
  m = surf(x,y,z);
  m.FaceColor = 'none';
  m.EdgeColor = 'none';
  m.Marker = 's';
  m.MarkerFaceColor = [.7 .2 .3];
  m.MarkerEdgeColor = 'none';
  hold off